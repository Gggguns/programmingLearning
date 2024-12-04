#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <locale>
#include <codecvt>
#include <Windows.h>

using namespace std;

// 判断运算符的优先级
int precedenceLogical(wchar_t op) {
    if (op == L'¬') return 3;  // NOT
    if (op == L'∧') return 2;  // AND
    if (op == L'∨') return 1;  // OR
    if (op == L'→' || op == L'↔') return 0;  // IMPLIES or BICONDITIONAL
    return -1;
}

// 判断是否是命题逻辑运算符
bool isLogicalOperator(wchar_t c) {
    return (c == L'¬' || c == L'∧' || c == L'∨' || c == L'→' || c == L'↔');
}

// 将命题逻辑中缀表达式转换为后缀表达式（逆波兰式）
wstring infixToPostfixLogical(const wstring& expression) {
    stack<wchar_t> operators;  // 运算符栈
    wstring result;  // 存储输出的后缀表达式

    for (size_t i = 0; i < expression.size(); ++i) {
        wchar_t c = expression[i];

        // 如果是字母，直接加入输出队列
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += c;
        }
        else if (c == '(') {
            operators.push(c);  // 左括号直接入栈
        }
        else if (c == ')') {
            // 右括号，弹出栈中的运算符直到遇到左括号
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                    operators.pop();
            }
            operators.pop();  // 弹出左括号
        }
        else if (isLogicalOperator(c)) {
            // 逻辑运算符，弹出栈中优先级较高的运算符
            while (!operators.empty() && operators.top() != '(' && precedenceLogical(operators.top()) >= precedenceLogical(c)) {
                result += operators.top();
                operators.pop();
            }
            operators.push(c);  // 当前逻辑运算符入栈
        }
    }

    // 弹出栈中的所有运算符
    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }

    return result;
}


int Print(std::wstring wstr) {

    // 获取转换后的字符串的长度
    int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);

    // 创建一个缓冲区以保存转换后的 UTF-8 字符串
    char* buffer = new char[bufferSize];

    // 执行转换
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, buffer, bufferSize, nullptr, nullptr);

    // 使用 std::cout 输出 UTF-8 字符串
    std::cout << buffer << std::endl;

    // 释放内存
    delete[] buffer;

    return 0;
}


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
   
    wstring expressionLogic = L"¬P∧Q";
    wstring resultLogic = infixToPostfixLogical(expressionLogic);
    cout << "Infix (Logical): ";
    Print(expressionLogic);
    cout << "Postfix (Logical): ";
    Print(resultLogic);
    return 0;
}





//// 判断运算符的优先级
//int precedence(char op) {
//    if (op == '+' || op == '-') return 1;
//    if (op == '*' || op == '/') return 2;
//    return 0;
//}
//
//// 判断是否是运算符
//bool isOperator(char c) {
//    return (c == '+' || c == '-' || c == '*' || c == '/');
//}
//
//// 将中缀表达式转换为后缀表达式（逆波兰式）
//string infixToPostfix(const string& expression) {
//    stack<char> operators;  // 运算符栈
//    string result;  // 存储输出的后缀表达式
//
//    for (char c : expression) {
//        if (isdigit(c)) {
//            result += c;  // 如果是操作数（数字），直接添加到结果
//        }
//        else if (c == '(') {
//            operators.push(c);  // 左括号直接入栈
//        }
//        else if (c == ')') {
//            // 右括号，弹出栈中的运算符直到遇到左括号
//            while (!operators.empty() && operators.top() != '(') {
//                result += operators.top();
//                operators.pop();
//            }
//            operators.pop();  // 弹出左括号
//        }
//        else if (isOperator(c)) {
//            // 运算符，弹出栈中优先级较高的运算符
//            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
//                result += operators.top();
//                operators.pop();
//            }
//            operators.push(c);  // 当前运算符入栈
//        }
//    }
//
//    // 弹出栈中的所有运算符
//    while (!operators.empty()) {
//        result += operators.top();
//        operators.pop();
//    }
//
//    return result;
//}
//
//int main() {
//    string expression = "3+(2*5)*(2+5*7)";
//    string result = infixToPostfix(expression);
//    cout << "Infix: " << expression << endl;
//    cout << "Postfix: " << result << endl;
//
//    return 0;
//}
