#include <note.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>

/**
 * definition for an object that holds a frequency and its name in the standard note declaration.
 * begins with c0 -> 16,5Hz; has all 107 standard western notes.
 * @brief Note::Note
 * @param note
 */


/**
 * Just an unordered list of pairs, notes[index].first get's the name, .second get's the frequency of the note
 * formular for frequencies: freq = 444.0 * pow(2.0,(index - 69.0)/12.0)
 **/
std::pair<std::string,float> notes[108] =
    {
     std::make_pair( "C0",16.35)
   , std::make_pair("C#0",17.32)
   , std::make_pair( "D0",18.35)
   , std::make_pair("D#0",19.45)
   , std::make_pair( "E0",20.60)
   , std::make_pair( "F0",21.83)
   , std::make_pair("F#0",23.12)
   , std::make_pair( "G0",24.50)
   , std::make_pair("G#0",25.96)
   , std::make_pair( "A0",27.50)
   , std::make_pair("A#0",29.14)
   , std::make_pair( "B0",30.87)
   , std::make_pair( "C1",32.70)
   , std::make_pair("C#1",34.65)
   , std::make_pair( "D1",36.71)
   , std::make_pair("D#1",38.89)
   , std::make_pair( "E1",41.20)
   , std::make_pair( "F1",43.65)
   , std::make_pair("F#1",46.25)
   , std::make_pair( "G1",49.00)
   , std::make_pair("G#1",51.91)
   , std::make_pair( "A1",55.00)
   , std::make_pair("A#1",58.27)
   , std::make_pair( "B1",61.74)
   , std::make_pair( "C2",65.41)
   , std::make_pair("C#2",69.30)
   , std::make_pair( "D2",73.42)
   , std::make_pair("D#2",77.78)
   , std::make_pair( "E2",82.41)
   , std::make_pair( "F2",87.31)
   , std::make_pair("F#2",92.50)
   , std::make_pair( "G2",98.00)
   , std::make_pair("G#2",103.83)
   , std::make_pair( "A2",110.00)
   , std::make_pair("A#2",116.54)
   , std::make_pair( "B2",123.47)
   , std::make_pair( "C3",130.81)
   , std::make_pair("C#3",138.59)
   , std::make_pair( "D3",146.83)
   , std::make_pair("D#3",155.56)
   , std::make_pair( "E3",164.81)
   , std::make_pair( "F3",174.61)
   , std::make_pair("F#3",185.00)
   , std::make_pair( "G3",196.00)
   , std::make_pair("G#3",207.65)
   , std::make_pair( "A3",220.00)
   , std::make_pair("A#3",233.08)
   , std::make_pair( "B3",246.94)
   , std::make_pair( "C4",261.63)
   , std::make_pair("C#4",277.18)
   , std::make_pair( "D4",293.66)
   , std::make_pair("D#4",311.13)
   , std::make_pair( "E4",329.63)
   , std::make_pair( "F4",349.23)
   , std::make_pair("F#4",369.99)
   , std::make_pair( "G4",392.00)
   , std::make_pair("G#4",415.30)
   , std::make_pair( "A4",440.00)
   , std::make_pair("A#4",466.16)
   , std::make_pair( "B4",493.88)
   , std::make_pair( "C5",523.25)
   , std::make_pair("C#5",554.37)
   , std::make_pair( "D5",587.33)
   , std::make_pair("D#5",622.25)
   , std::make_pair( "E5",659.25)
   , std::make_pair( "F5",698.46)
   , std::make_pair("F#5",739.99)
   , std::make_pair( "G5",783.99)
   , std::make_pair("G#5",830.61)
   , std::make_pair( "A5",880.00)
   , std::make_pair("A#5",932.33)
   , std::make_pair( "B5",987.77)
   , std::make_pair( "C6",1046.50)
   , std::make_pair("C#6",1108.73)
   , std::make_pair( "D6",1174.66)
   , std::make_pair("D#6",1244.51)
   , std::make_pair( "E6",1318.51)
   , std::make_pair( "F6",1396.91)
   , std::make_pair("F#6",1479.98)
   , std::make_pair( "G6",1567.98)
   , std::make_pair("G#6",1661.22)
   , std::make_pair( "A6",1760.00)
   , std::make_pair("A#6",1864.66)
   , std::make_pair( "B6",1975.53)
   , std::make_pair( "C7",2093.00)
   , std::make_pair("C#7",2217.46)
   , std::make_pair( "D7",2349.32)
   , std::make_pair("D#7",2489.02)
   , std::make_pair( "E7",2637.02)
   , std::make_pair( "F7",2793.83)
   , std::make_pair("F#7",2959.96)
   , std::make_pair( "G7",3135.96)
   , std::make_pair("G#7",3322.44)
   , std::make_pair( "A7",3520.00)
   , std::make_pair("A#7",3729.31)
   , std::make_pair( "B7",3951.07)
   , std::make_pair( "C8",4186.01)
   , std::make_pair("C#8",4434.92)
   , std::make_pair( "D8",4698.63)
   , std::make_pair("D#8",4978.03)
   , std::make_pair( "E8",5274.04)
   , std::make_pair( "F8",5587.65)
   , std::make_pair("F#8",5919.91)
   , std::make_pair( "G8",6271.93)
   , std::make_pair("G#8",6644.88)
   , std::make_pair( "A8",7040.00)
   , std::make_pair("A#8",7458.62)
   , std::make_pair( "B8",7902.13)
    };

/**
 * create a note from a name
 * @brief Note::Note
 * @param note
 */
Note::Note(std::string note)
{
    index = this->getNoteIndex(note);
    frequency = notes[index].second;
    name = notes[index].first;
}

/**
 * Find the right note for a frequency (currently exact values, 'find_nearest_note()'?)
 * @brief Note::Note
 * @param freq
 */
Note::Note(float freq)
{
    index = this->getNoteIndex(freq);
    frequency = notes[index].second;
    name = notes[index].first;
}

/**
 * to find notes like c7 and to make it easier for a slider,
 * get a note from an index(from low to high key notes)
 * @brief Note::Note
 * @param number
 */
Note::Note(int number)
{
    index = number;
    frequency = notes[number].second;
    name = notes[number].first;
}

/**
 * @Todo divide and conquer, at least on frequency
 * @brief Note::getNoteName
 * @param number
 * @return
 */
std::string Note::getNoteName(int number)
{
    return notes[number].first;
}

/**
 * @TODO divide and conquer, start in the middle and go in the right direction
 * @brief Note::getNoteName
 * @param freq
 * @return
 */
std::string Note::getNoteName(float freq)
{
    for(int i=0;i<=107;i++)
    {
        if(notes[i].second == freq) return notes[i].first;
    }

    // Might not be the best thing since Qt doesn't seem to like exceptions(who does?)
    throw std::invalid_argument("Not a frequency belonging to a note");
    return NULL;
}

float Note::getNoteFrequency(int number)
{
    if(number>107)
    {
        std::ostringstream stringstream;
        stringstream << "There are only 108 notes, \'" << number << "\' dosn't exist";
        throw std::invalid_argument(stringstream.str());
    }

    return notes[number].second;
}

/**
 * @TODO find a way to divide and conquer: find first occurence of major note (i.e c0 or c0#) and add 12 to it
 * or just calc it "C#2" -> 2*12*1 or something
 * @brief Note::getNoteFrequency
 * @param name
 * @return
 */

float Note::getNoteFrequency(std::string name)
{
    for(int i=0;i<=107;i++)
    {
        if(notes[i].first == name) return notes[i].second;
    }
    throw std::invalid_argument("There is no such note.");
    return 0;
}

int Note::getNoteIndex(std::string name)
{
    for(int i=0;i<=107;i++)
    {
        if(notes[i].first == name) return i;
    }
    throw std::invalid_argument("There's no such note. <Index>");
    return 0;
}

int Note::getNoteIndex(float freq)
{
    for(int i=0;i<=107;i++)
    {
        if(notes[i].second == freq)return i;
    }

    throw std::invalid_argument("This frequency doesn't belong to any note");
    return 0;
}

std::string Note::getName()
{
    return name;
}

float Note::getFrequency()
{
    return frequency;
}
