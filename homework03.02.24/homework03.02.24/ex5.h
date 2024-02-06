#pragma once
#include <iostream>
using namespace std;

class DocumentControl;

class Document {
private:
	string theme;
	string text;
public:
	Document(string theme, string text) : theme(theme), text(text)
	{}
	friend class DocumentControl;
	void getDocData() {
		cout << "Doc. theme: " << theme << endl;
		cout << "Text: " << text << endl;
	}
	//void callFriendThemeChanger(Document& doc);
	//void callFriendTextChanger(Document& doc);
};

class DocumentControl {
public:
	static Document createDoc() {
		string new_theme;
		string new_text;
		cout << "Input doc. theme: ";
		cin >> new_theme;
		cout << "Input text: ";
		cin >> new_text;
		Document new_doc(new_theme, new_text);
		return new_doc;
	}
	static void changeDocTheme(Document& doc) {
		string new_theme;
		cout << "Input new doc. theme: ";
		cin >> new_theme;
		doc.theme = new_theme;
	}
	static void changeDocText(Document& doc) {
		string new_text;
		cout << "Input new text: ";
		cin >> new_text;
		doc.text = new_text;
	}

	//void callFriendThemeChanger(Document& doc);
	//void callFriendTextChanger(Document& doc);
};
//
//void Document::callFriendThemeChanger(Document& doc) {
//	doc.
//}
//
//void Document::callFriendTextChanger(Document& doc) {
//	
//}

//void DocumentControl::callFriendThemeChanger(Document& doc)
//{
//	changeDocTheme(doc);
//}
//
//void DocumentControl::callFriendTextChanger(Document& doc)
//{
//	changeDocText(doc);
//}

void ex5() {
	//Document doc1 = DocumentControl::createDoc();
	Document doc1("MyTheme", "MyText");
	doc1.getDocData();
	DocumentControl::changeDocTheme(doc1);
	DocumentControl::changeDocText(doc1);
	doc1.getDocData();
}