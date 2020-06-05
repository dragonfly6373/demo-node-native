#include <node.h>

namespace hw {
  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void Sum(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    double total = args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
    args.GetReturnValue().Set(Number::New(isolate, total));
  }

  void hello(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World!"));
  }

  void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "hello", hello);
    NODE_SET_METHOD(exports, "sum", Sum);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
} 
