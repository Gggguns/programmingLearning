﻿#ifndef _doyou_io_DBUser_HPP_
#define _doyou_io_DBUser_HPP_

#include"Log.hpp"
#include"DBManager.hpp"

namespace doyou {
	namespace io {

		//消息分发
		class DBUser:public DBManager
		{
		protected:
			int64 _max_userId = 100000;
		public:
			~DBUser()
			{
				close();
			}
		
			int64 makeId()
			{
				return _max_userId+1;
			}
		protected:
			void load_id()
			{
				neb::CJsonObject json;
				execQuery("SELECT MAX(userId) FROM user_info;", json);
				if (json.IsArray() && json.GetArraySize() > 0)
				{
					int64 max_id = 0;
					if (json[0].Get("MAX(userId)", max_id))
					{
						if (max_id == 0)
							return;
						_max_userId = max_id;
					}
				}
			}

			bool create_table_user_info()
			{
				auto sql =
					"\
CREATE TABLE user_info(\
	id          INTEGER PRIMARY KEY,\
	userId      INTEGER UNIQUE,\
	username    TEXT    UNIQUE,\
	password    TEXT    NOT NULL,\
	nickname    TEXT    UNIQUE,\
	sex         INTEGER,\
	state       INTEGER,\
	create_date INTEGER\
);\
";
				if (!tableExists("user_info"))
				{
					return execDML(sql) != -1;
				}
				return true;
			}
		public:
			void init()
			{
				if (!open("user.db"))
				{
					CELLLog_Info("DBUser::init(%s.%s) failed.", _db_name.c_str(), "user_info");
					return;
				}

				if (!create_table_user_info())
				{
					CELLLog_Info("DBUser::init(%s.%s) failed.", _db_name.c_str(), "user_info");
					return;
				}

				load_id();

				begin();
				CELLLog_Info("DBUser::init(%s.%s) success.", _db_name.c_str(), "user_info");
			}

			bool has_username(const std::string& username)
			{
				return hasByKV("user_info", "username", username.c_str());
			}

			bool has_nickname(const std::string& nickname)
			{
				return hasByKV("user_info", "nickname", nickname.c_str());
			}

			int64 add_user(const std::string& username, const std::string& password, const std::string& nickname, int sex)
			{
				int64 userId = makeId();
				//sql = "INSERT INTO user_info (userId, username, password, nickname, sex, state, create_date) VALUES (%lld, '%s', '%s', '%s', %d, %d, %lld);
				std::stringstream ss;
				ss << "INSERT INTO user_info (userId, username, password, nickname, sex, state, create_date) VALUES (";
				ss << userId<<", ";
				ss << "'" << username << "', ";
				ss << "'" << password << "', ";
				ss << "'" << nickname << "', ";
				ss << sex << ", ";
				ss << 0 << ", ";
				ss << Time::system_clock_now() << ");";

				int changes = execDML(ss.str().c_str());

				//CELLLog_Info("DBUser::add_user changes=%d", changes);
				if (changes > 0)
				{
					++_max_userId;
					return userId;
				}
				return 0;
			}
		};
	}
}
#endif // !_doyou_io_DBUser_HPP_
