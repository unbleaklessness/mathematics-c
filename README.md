## Building

### Dependencies:
**Check** - unit test C library: [https://libcheck.github.io/check/](https://libcheck.github.io/check/).

### Steps:
- `git clone --recurse-submodules https://github.com/unbleaklessness/mathematics-cpp`.
- `cd mathematics-cpp`.
- `mkdir build`.
- `cd build`.
- `cmake .. && make && make install`.

### Output:
- `lib` - static library.
- `include` - header files.
- `bin` - unit tests executable.