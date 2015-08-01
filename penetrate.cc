#include <node.h>
#include <v8.h>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace v8;

void penetrate(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);
	v8::String::Utf8Value str(args[0]->ToString());
	#ifdef _WIN32
	char *name = *str;
	HWND h = FindWindow(NULL,(LPCSTR)name);
	if (h != NULL) {
		int extendedStyle = GetWindowLong(h, GWL_EXSTYLE);
		SetWindowLong(h, GWL_EXSTYLE, extendedStyle | WS_EX_TRANSPARENT | WS_EX_LAYERED);
		args.GetReturnValue().Set(true);
		return;
	}
	#endif
	args.GetReturnValue().Set(false);
}

void Init(Handle<Object> exports) {
	Isolate* isolate = Isolate::GetCurrent();
	exports->Set(String::NewFromUtf8(isolate, "penetrate"),
		FunctionTemplate::New(isolate, penetrate)->GetFunction());
}

NODE_MODULE(penetrate, Init)
