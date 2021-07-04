//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "lua.h"      
#include "lauxlib.h"      
#include "lualib.h"

using namespace LuaBox;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void LuaBox::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{	
	char buff[256] = "x = 42; y = 1337; print(x,y)";
	int error;
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
	if (error) {
		OutputDebugStringA("LUA ERROR:\n");
		OutputDebugStringA(lua_tostring(L, -1));
		OutputDebugStringA("\n");
		lua_pop(L, 1);
	}
	
	int n = lua_gettop(L);
	if (n > 0) {  /* any result to be printed? */
		OutputDebugStringA("printing results...\n");
		luaL_checkstack(L, LUA_MINSTACK, "too many results to print");
		lua_getglobal(L, "print");
		lua_insert(L, 1);
		lua_pcall(L, n, 0, 0);
	}

	lua_close(L);
}
