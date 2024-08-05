#include <iostream>
#include <exiv2/exiv2.hpp>

void removeMetadata(const std::string &filename)
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

        // Read and clear metadata
        image->readMetadata();
        image->clearMetadata(); // Removes all metadata
        image->writeMetadata();

        std::cout << "Metadata removed from " << filename << std::endl;
    }
    catch (const Exiv2::Error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    std::string filename;
    std::cout << "Enter the filename to remove metadata: ";
    std::cin >> filename;
    removeMetadata(filename);
    return 0;
}

