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

LuaState luaState;
lua_State* L;

MainPage::MainPage()
{
	InitializeComponent();
	state.result = "fugg";
	L = luaL_newstate();
	luaL_openlibs(L);
}

void LuaBox::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{	
	Platform::String^ input = InputLine->Text;
	wchar_t const* wchars = input->Data();
	char line[2560];
	sprintf(line, "%ws", wchars);
	int error;

	doREPL(L, line);

	ResultLabel->Text = luaState.result;
}
