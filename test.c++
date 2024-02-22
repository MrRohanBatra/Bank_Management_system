#include <iostream>
#include <fstream>

int main() {
    // Create an output file stream object
    // system("mkdir sources\\password\\");
    system("mkdir sources\\password\\");
    system("cd sources\\password\\");
    std::ofstream outfile("password.dat");

    // Check if file was created successfully
    if (outfile.is_open()) {
        std::cout << "File created successfully!" << std::endl;

        // Write data to the file (replace with your content)
        outfile << "This is some text in the new file." << std::endl;

        // Close the file
        outfile.close();
    } else {
        std::cerr << "Error creating file!" << std::endl;
    }
    system("cd ..\\..");

    return 0;
}
