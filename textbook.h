#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <vector>
#include <string>

//Vector methods:
//vector<type> name; to initialize
//name.push_back(value) insert a value of <type> to the end of the vector.
//name.at(index) returns the element at that index.
//name.size() returns an unsigned integer equal to the size of the vector.
//name.begin() reads through the vector, beginning with index 0.
//name.insert( name.begin() + x, value) insert a value just before 'x' spaces after the first index.
//name.clear() erases all elements from the vector.
//name.isEmpty() returns a boolean determining whether the vector is empty or not.

class Textbook
{
public:
    Textbook();
    void createChapter(string chapterName, Note mainNote);
    void createChapter(string chapterName);
    void deleteChapter(Chapter chapter);
    void grantAdmin(Student student);
    bool isAdmin(Student student);
    void setOriginalAdmin(Student student);
    Student getOriginalAdmin();
private:
    Student originalAdmin;
    vector<Student> admins;
};

#endif // TEXTBOOK_H
