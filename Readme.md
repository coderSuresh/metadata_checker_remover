# Metadata Checker & Remover

A simple tool built in C++ using <a href="https://exiv2.org/download.html" target="_blank">`exiv2`</a> library to check and remove metadata from images.

Currently tested in Linux (Ubuntu)

## Compile & Run

Compiling `metadata_checker.cpp`
```
g++ -std=c++17 -o metadata_checker metadata_checker.cpp -I/path/to/exiv2-0.28.3-Linux64/include -L/path/to/exiv2-0.28.3-Linux64lib -lexiv2
```

Running `metadata_checker`

```
./metadata_checker
```

Compiling `metadata_remover.cpp`

```
g++ -std=c++17 -o metadata_remover metadata_remover.cpp -I/path/to/exiv2-0.28.3-Linux64/include -L/path/to/exiv2-0.28.3-Linux64lib -lexiv2
```

Running `metadata_remover`

```
./meteadata_remover
```