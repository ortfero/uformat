# uformat

C++ header-only library to format text



## Usage

Just put all files from `include/uformat` at your include path



## Tests

To run tests:

```shell
cd uformat
mkdir build
cd build
cmake ../test
```



## Snippets


### Fixed strings

```cpp
namespace uf = uformat;
uf::fixed_string<508> text{"Roses are red"};
uf::string roses{text.substr(0, 5)}; // "Roses"
```


### Text formatting

```cpp
uformat::fixed_texter texter;
texter.print("Value: ", -127562.127562); // texter contains "Value: -127562.127562"

```

### Benchmarks

#### Formatting

| Code                                                         | Time (ns) | Ratio |
|--------------------------------------------------------------|----------:|------:|
| ```texter.print('a');```                                     | 1.3       | x1    |
| ```snprintf(charz, sizeof (charz), "%c", 'a');```            | 212.0     | x163  |
| ```fmt::format_to(charz, "{}", 'a');```                      | 187.0     | x143  |
| ```texter.print("some literal");```                          | 1.3       | x1    |
| ```snprintf(charz, sizeof (charz), "%s", "some literal");``` | 141.5     | x108  |
| ```fmt::format_to(charz, "{}", "some literal");```           | 63.9      | x49   |
| ```texter.print(-127562);```                                 | 7.7       | x1    |
| ```snprintf(charz, sizeof (charz), "%d", -127562);```        | 220.5     | x28   |
| ```fmt::format_to(charz, "{}", -127562);```                  | 79.3      | x10   |
| ```texter.print(-127562.127562);```                          | 8.2       | x1    |
| ```snprintf(charz, sizeof (charz), "%f", -127562.127562);``` | 775.0     | x94   |
| ```fmt::format_to(charz, "{}", -127562.127562);```           | 412.0     | x50   |
