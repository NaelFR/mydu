#include <iostream>
#include <iomanip>      // std::setw
#include <boost/filesystem.hpp>
#include <math.h>       /* pow */


using namespace boost::filesystem;
using namespace std;


uintmax_t visitFolder(const path &p, int limit) {
    uintmax_t size = 0;

    try {
        if (exists(p)) {
            if (is_regular_file(p))
                 cout << p << " size is " << file_size(p) << '\n';
            if (is_directory(p)) {
                // cout << p << " is a directory containing:\n";
                // size += 4;
                // size += 4;
                size += 4096;
                for (directory_entry &x : directory_iterator(p)) {
                    if (x.path() == "." || x.path() == "..") {
                        size += 4096;
                    }
                    if (is_regular_file(x.path())) {
                        // cout << setw(5) << left << file_size(x.path()) << "\t" << x.path().string() << endl;

                        size += file_size(x.path()) ;
                    } else if (is_directory(x.path())) {
                        size += 4096;
                        if (limit == -1) {
                            size += visitFolder(x.path(), -1);
                        } else {
                            size += visitFolder(x.path(), limit - 1);
                        }
                    }
                }
            }
            // cout << p << " exists, but is not a regular file or directory\n";

            uintmax_t size_kios = size >> 0;
            cout << setw(5) << left << size_kios << "\t" << p.string() << endl;
        }
        return size;
        // else
        // cout << p << " does not exist\n";
    }

    catch (const filesystem_error &ex) {
        cout << ex.what() << '\n';
    }
}

int main(int argc, char *argv[]) {


    visitFolder(path("."), -1);

    return 0;
}

