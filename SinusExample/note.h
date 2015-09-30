#ifndef NOTE
#define NOTE
#include <string>

class Note
{
public:
    ~Note(){}
    Note(std::string note);
    Note(int number);
    Note(float freq);
    /**
     * name of the note - e.g: cn,dn,en,fn,gn,an,bn and their halfnotes
     **/
    std::string name;
    float frequency;
    int index;

    float getFrequency(void);
    std::string getName(void);

    int setNote(std::string note);

    static std::string getNoteName(float freq);
    static std::string getNoteName(int number);

    static float getNoteFrequency(std::string);
    static float getNoteFrequency(int number);

    static int getNoteIndex(std::string name);
    static int getNoteIndex(float freq);

};

#endif // NOTE
