#ifndef SCENE_FILE_HPP
#define SCENE_FILE_HPP
#include <string>

class SceneFile
{
public:
    SceneFile(){}
    ~SceneFile(){}

    void loadFromFile(const std::string& filename)
    {}
    void saveToFile(const std::string& filename) const
    {}

private:
    // Scene data members
};

#endif // SCENE_FILE_HPP