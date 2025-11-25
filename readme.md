**QapGen Installation, Usage, and Getting Started Guide**

**How to Install and Run QapGen**

1. Clone the repository:
```bash
git clone https://github.com/adler3d/QapGen
```

2. Go to the stable build directory:
```bash
cd QapGen/stable
```

3. Make the build script executable:
```bash
chmod +x build.sh
```

4. Run the build script:
```bash
./build.sh
```

5. Navigate to the Release folder:
```bash
cd Release
```

6. Run QapGen with your grammar file:
```bash
./QapGen.elf your_grammar_file.qapdsl.hpp dontoptimize_polymorphs > output.inl
```

If everything works correctly, the file `output.inl` will be generated.

**Integrate `output.inl` into Your Project**

You can integrate the generated `output.inl` file into your own project.

A simple example project is the **Simple Calculator**, available here:
```cpp
https://github.com/adler3d/QapGen/tree/master/src/SimpleCalc
```
Steps to use `output.inl` with SimpleCalc:

1. Open the file:
`QapGen/src/SimpleCalc/SimpleCalc/SimpleCalc.cpp`
2. Replace the line:
`#include "t_simple_calc.inl"`
with
`#include "output.inl"`
3. Place the `output.inl` file in the same directory as `SimpleCalc.cpp`.
4. Remove the class `t_simple_calc_evaluator` from the project.
5. Modify the `main_2021` function to the following minimal example:
```cpp
string input = "your_script_or_code_or_text";
TAutoPtr<t_your_root_lexer> root_lexer; // load_obj almost always don't work without TAutoPtr
auto ok = load_obj(root_lexer, input);
if (!ok) return;
// Then traverse the tree stored in root_lexer using visitors or your functions
```

**Build and Run the SimpleCalc Project**

To build and run on Linux/macOS:

```bash
g++ -O2 -std=c++17 SimpleCalc.cpp -o SimpleCalc.elf
./SimpleCalc.elf
```

**For Windows Users**

There is a Visual Studio 2017 solution file `SimpleCalc.sln` and a build batch script `build.bat` located in:
`QapGen/src/SimpleCalc`

Open the solution in MS Visual Studio 2017 and build the project there.

**Summary**

- Clone and build QapGen.
- Generate `output.inl` from your grammar file.
- Integrate `output.inl` into your project (e.g., SimpleCalc).
- Adjust your main code to load and traverse the parsed tree.
- Build and run your project.

This will help you quickly start working with QapGen-generated parsers and lexers.
