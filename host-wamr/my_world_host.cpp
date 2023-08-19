// Generated by `wit-bindgen` 0.1.0. DO NOT EDIT!
#include "my_world_cpp_host.h"
#include <wasm_export.h> // wasm-micro-runtime header


// Component Adapters
static int32_t host_test_example_my_interface_constructor_my_object(wasm_exec_env_t exec_env, uint32_t a) {
  auto call_result = new ::test::example::my_interface::MyObject(a);
  return call_result->id;
}
static void host_test_example_my_interface_method_my_object_set(wasm_exec_env_t exec_env, int32_t self, uint32_t v) {
  dynamic_cast<test::example::my_interface::MyObject*>(my_world::ResourceBase::lookup_resource(self))->Set(v);
}
static uint32_t host_test_example_my_interface_method_my_object_get(wasm_exec_env_t exec_env, int32_t self) {
  return dynamic_cast<test::example::my_interface::MyObject*>(my_world::ResourceBase::lookup_resource(self))->Get();
}
static void host_test_example_my_interface_method_my_object_drop(wasm_exec_env_t exec_env, int32_t self) {
  delete my_world::ResourceBase::lookup_resource(self);
}
void register_my_world() {
    static NativeSymbol test_example_my_interface_funs[] = {
        { "[constructor]my-object", (void*)host_test_example_my_interface_constructor_my_object, "(i)i", nullptr },
        { "[method]my-object.set", (void*)host_test_example_my_interface_method_my_object_set, "(ii)", nullptr },
        { "[method]my-object.get", (void*)host_test_example_my_interface_method_my_object_get, "(i)i", nullptr },
        { "[resource-drop]my-object", (void*)host_test_example_my_interface_method_my_object_drop, "(i)", nullptr },
    };
    wasm_runtime_register_natives("test:example/my-interface", test_example_my_interface_funs, sizeof(test_example_my_interface_funs)/sizeof(NativeSymbol));
}
