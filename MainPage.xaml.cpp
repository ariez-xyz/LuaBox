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
	char buff[256] = "x = 4; y = 3 + x;";
	int error;
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
	OutputDebugStringA(lua_tostring(L, -1));
	if (error) {
		lua_pop(L, 1);
	}

	lua_close(L);
}
