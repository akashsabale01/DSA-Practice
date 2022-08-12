#include <iostream>
#include <fstream> /* fstream header file for ifstream, ofstream, fstream classes */

using namespace std;

int main()
{
    string info;
    cout << "Enter paragraph = ";
    getline(cin, info); // get full line
    // cin >> info; // get only till space

    // 1) Write into file

    // ofstream used to write in file or used to create file
    // File opened in ios::out mode by default when we create object of ofstream class
    // ios::out => for inserting data into file, ios::in => for reading data from file
    // ios::append => for appending to exiting file
    ofstream myfile("destination.txt");
    myfile << info;
    myfile.close();
    cout << endl
         << "File write operation performed successfully" << endl;

    cout << endl;
    // 2) Read from file
    // string outputString;
    // ifstream readObj("destination.txt");
    // // Use a while loop together with the getline() function to read the file line by line
    // while (getline(readObj, outputString))
    // {
    //     // Output the text from the file
    //     cout << outputString;
    // }
    // readObj.close();

    ifstream readObj("destination.txt");

    cout << endl;

    return 0;
}

// https://www.codezclub.com/cpp-solved-programs-problems-solutions/cpp-file-handling-solved-programs-solutions/

// Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Eget est lorem ipsum dolor sit amet consectetur adipiscing. Netus et malesuada fames ac. Et tortor at risus viverra adipiscing. Mi in nulla posuere sollicitudin. Aliquam eleifend mi in nulla posuere sollicitudin aliquam ultrices sagittis. Eu turpis egestas pretium aenean pharetra. Mauris augue neque gravida in fermentum et sollicitudin. Semper feugiat nibh sed pulvinar proin gravida hendrerit lectus. Enim nulla aliquet porttitor lacus. Faucibus a pellentesque sit amet. Quis auctor elit sed vulputate mi sit amet. Diam phasellus vestibulum lorem sed risus ultricies tristique nulla aliquet. Imperdiet proin fermentum leo vel orci porta non pulvinar neque. Integer eget aliquet nibh praesent tristique magna sit amet purus. Interdum velit euismod in pellentesque. Proin fermentum leo vel orci.

// Ut enim blandit volutpat maecenas volutpat blandit aliquam etiam erat. Condimentum lacinia quis vel eros donec ac odio tempor orci. Sit amet nisl purus in mollis nunc. Lorem ipsum dolor sit amet consectetur adipiscing. Sed odio morbi quis commodo. Tristique risus nec feugiat in fermentum posuere urna nec tincidunt. Eget est lorem ipsum dolor sit. Ut porttitor leo a diam sollicitudin. Maecenas pharetra convallis posuere morbi leo urna. Ullamcorper velit sed ullamcorper morbi tincidunt ornare massa eget egestas. Tristique sollicitudin nibh sit amet commodo nulla facilisi. Sed blandit libero volutpat sed cras ornare arcu. Non blandit massa enim nec. Pellentesque pulvinar pellentesque habitant morbi tristique senectus et netus. Sed lectus vestibulum mattis ullamcorper velit sed. Velit sed ullamcorper morbi tincidunt ornare massa eget egestas purus. Elit pellentesque habitant morbi tristique senectus et.

// Eget aliquet nibh praesent tristique magna sit. Tristique et egestas quis ipsum suspendisse ultrices gravida dictum. Mauris nunc congue nisi vitae suscipit tellus mauris a diam. Mi proin sed libero enim sed faucibus. Fusce id velit ut tortor pretium. Bibendum ut tristique et egestas quis ipsum. Sed arcu non odio euismod lacinia at quis risus. Morbi tristique senectus et netus et. Pellentesque habitant morbi tristique senectus et netus et. Sit amet consectetur adipiscing elit.