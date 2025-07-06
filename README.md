# QapGen

> Detailed overview: [QapDSL: declarative AST and parsers for C++ (Habr)](https://habr.com/ru/articles/916006/)

QapGen is an autogenerator of C++ structures, AST and parsers according to the declarative scheme (QapDSL).

...

# How to use it in general?
<pre>
Like this:
    Write a script/code in QapDSL.
    Save it in samples/input.qapdsl
    Run QapGen.exe
    Take the generated C++ code from the opened window.
    Paste it into https://github.com/adler3d/unordered/blob/master/code/SimpleCalc/Sgon/CommonUnit.cpp somewhere near the main function (you still need to find it). // this point needs to be improved.
    In main, write TAutoPtr&lt;your_root_node&gt; root;
    load_obj(Env,root,your_string_from_which_you_need_to_load_code_into_AST);
    Use the AST you just loaded into root.
    ...
    Profit!
</pre>
...

# Comparison: QapDSL, tree-sitter, syn, TreeDL, Clang LibTooling

## 1. General purpose and scope

| System | Main purpose | Task type |
|------------------|---------------------------------------------|---------------------------|
| QapDSL | Parsing, AST, compact DSL, code autogeneration | Translators, DSL, analysis |
| tree-sitter | Fast parser for editors, incremental syntax analysis | IDE, editors, highlighting |
| syn (Rust) | Parsing Rust code into procedural macros | Macros, code-gen for Rust|
| TreeDL | Declarative AST description, code generation for AST | Compilers, analyzers |
| Clang LibTooling | Tools for working with C/C++ AST, parsing, refactoring | Analysis, refactoring, IDE |

---

## 2. Approach to describing grammar and structure

| System | Grammar description | AST description | Integration of actions |
|------------------|----------------------------|------------------------------|-------------------------------|
| QapDSL | Yes (flexibly, in the style of C++ code)| Yes (via classes/structures) | No |
| tree-sitter | Yes (JS/C object rules) | Automatically from grammar | No |
| syn (Rust) | No (manual parsing of syn::*) | Yes (Rust structures/Enums) | Yes, outside syntax |
| TreeDL | No (AST structure only) | Yes (very formal) | No |
| Clang LibTooling | No (ready-made grammar) | Yes (ready-made C++ AST classes) | Yes, via C++ API |

---

## 3. Incrementality, speed, integration

| System | Incremental parsing | Speed ​​| Embedding in IDEs/editors | Support languages ​​|
|------------------|----------------------------|-----------------|----------------------------|-------------------------|
| QapDSL | No | High | Can be embedded, but manually | Any in description |
| tree-sitter | Yes | Very high | IDE, editors (VSCode, NeoVim)| Multilingual (via gram.)|
| syn (Rust) | No | Medium/high | Rust only (build/macros) | Rust only |
| TreeDL | No | High | No (gen-code for AST) | Any (C++, Java, Py...)|
| Clang LibTooling | No | Medium | Great for IDE/refactors | C/C++ only |

---

## 4. Working with AST and actions

| System | Explicit AST | Related actions | Code generation/transformations | API for custom logic |
|------------------|-----------|------------------------|------------------------------|----------------------------------|
| QapDSL | Yes | No | No | No (only via C++ code extension, outside QapDSL) |
| tree-sitter | No | No | No | Yes (via tree-sitter API) |
| syn (Rust) | Yes | Yes (in procedural macros)| Yes (build macros/derive) | Yes (Rust API) |
| TreeDL | Yes | No | Yes (AST code generation) | No (structure only) |
| Clang LibTooling | Yes | Yes (C++ AST visitors) | Yes (via transformations) | Yes (C++ API) |

---

## 5. Coolness for different tasks

| System | Parser for editor | Code generation | Compiler | Analyzer | Refactoring | Quick start |
|------------------|---------------------|----------------|------------|-------------|--------------|--------------|
| QapDSL | +- | - | ++ | + | +- | ++ |
| tree-sitter | +++ | - | - | + | - | +++ |
| syn (Rust) | - | ++ | - | + | - | + |
| TreeDL | - | +++ | ++ | ++ | - | + |
| Clang LibTooling | + | + | + | +++ | +++ | - |

**Legend:**
<pre>
  +++ — ideal
  ++ — good
  + — usable
  +- — limited
  - — not intended
</pre>
---

## QapDSL: "API for custom logic"

QapDSL **does not provide an explicit API for custom logic** inside the DSL itself.
All logic is implemented only on the C++ side as methods/classes outside the QapDSL file.
Inside QapDSL, only go* method calls that return a flag (bool) are allowed, and after each call, this flag is checked to exit the function on error.
Example:

```cpp
bool go(i_dev& dev) {
  t_fallback scope(dev,__FUNCTION__);
  auto& ok = scope.ok;
  auto& M = scope.mandatory;
  M += dev.go_str<t_type>(type_name);
  if (!ok) return ok;
  // ... other steps
  return ok;
}
```
