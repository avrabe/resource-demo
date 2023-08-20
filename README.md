# A demo showing WASM component model resources in various environments

## Prerequisites

Rust with target wasm32-wasi

CMake

## Working

| |Guest|Host|
|---|---|---|
|C|wit-bindgen|[see below][1]|
|C++|cpetig/wit-bindgen|cpetig/wit-bindgen + WAMR|
|Rust|wit-bindgen|[see below][2]|
|JavaScript| jco? |jco|
|Go|[see below][3]| ? |
|Python|[see below][4]|[see below][4] |

## Compiling and Running

```bash
cd guest-rust
cargo build --target wasm32-wasi --release
cd ../host-wamr
mkdir build
cd build
cmake ..
make
./executor
```

Expected Output:

`drop with value 34`

### C guest

Prerequisite: wasi-SDK

```bash
cd guest-c
make
cd ..
ln -sf guest-c/guest-c.wasm guest.wasm 
```

## Regenerating C++ host bindings

```bash
git clone https://github.com/cpetig/wit-bindgen.git
cd wit-bindgen
cargo install --path .
cd ../host-wamr
wit-bindgen cpp-host ../wit/simple.wit
```

## Other environments

### Host languages

[2]
- Rust:

    Wasmtime host doesn't support generating bindings for resources.
    https://github.com/bytecodealliance/wasmtime/issues/6722


    Wasmer bindgen only supports the old witx, not the newer wit format. You could write a host binding generator within wit-bindgen though.

[1]
- C: Currently I generate C++ host bindings for WAMR, C would be feasible.

- Python: https://pypi.org/project/componentize-py/ (?)

### Guest languages

- JavaScript: https://github.com/bytecodealliance/javy is potentially smaller than spidermonkey embedded by jco, you will need another tool to generate guest bindings for imported functions, IIRC. A path using C bindings with yet to be written JavaScript wrapping should be viable.

[4]
- Python: https://pypi.org/project/componentize-py/ 

[3]
- Go: WIT bindgen support is being worked on https://github.com/bytecodealliance/SIG-Guest-Languages/blob/main/docs/subgroups.md
