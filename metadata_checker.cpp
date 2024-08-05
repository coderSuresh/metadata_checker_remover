#include <iostream>
#include <exiv2/exiv2.hpp>

void printMetadata(const std::string &filename)
{
    try
    {
        // Open the image file
        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
        if (!image)
        {
            std::cerr << "Failed to open image file." << std::endl;
            return;
        }

        // Read metadata
        image->readMetadata();
        Exiv2::ExifData &exifData = image->exifData();

        // Print metadata
        std::cout << "Metadata for " << filename << ":\n";
        for (const auto &entry : exifData)
        {
            std::cout << entry.key() << " = " << entry.value() << std::endl;
        }
    }
    catch (const Exiv2::Error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    std::string filename;
    std::cout << "Enter the filename to extract metadata: ";
    std::cin >> filename;
    printMetadata(filename);
    return 0;
}

