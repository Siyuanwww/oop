#include "editor.h"
#include <iostream>

TextEditor::TextEditor() {
    l = {0, 0};
    r = {-1, -1};
    selected = false;
    data.push_back("");
}
void TextEditor::moveCursor(Position dest) {
    l = dest;
    r = {-1, -1};
    selected = false;
}
void TextEditor::select(Position beg, Position end) {
    l = beg;
    r = end;
    selected = true;
}
void TextEditor::write(const std::string& str) {
    if (selected) {
        del();
    }
    data[l.Row].insert(l.Col, str);
    l.Col += str.size();
}
void TextEditor::newline() {
    if (selected) {
        del();
    }
    std::string str = data[l.Row];
    data[l.Row] = str.substr(0, l.Col);
    data.insert(data.begin() + l.Row + 1, str.substr(l.Col));
    l.Row++;
    l.Col = 0;
}
void TextEditor::del() {
    if (selected) {
        if (l.Row == r.Row) {
            data[l.Row].erase(l.Col, r.Col - l.Col);
        } else {
            data[l.Row].erase(l.Col);
            data[l.Row].append(data[r.Row].substr(r.Col));
            data.erase(data.begin() + l.Row + 1, data.begin() + r.Row + 1);
        }
        r = {-1, -1};
        selected = false;
    } else {
        if (l.Col == (int)data[l.Row].size() && l.Row != (int)data.size() - 1) {
            data[l.Row].append(data[l.Row + 1]);
            data.erase(data.begin() + l.Row + 1);
        } else if (l.Col < (int)data[l.Row].size()) {
            data[l.Row].erase(l.Col, 1);
        }
    }
}
void TextEditor::copy() {
    if (selected) {
        clipboard.clear();
        if (l.Row == r.Row) {
            clipboard.push_back(data[l.Row].substr(l.Col, r.Col - l.Col));
        } else {
            clipboard.push_back(data[l.Row].substr(l.Col));
            for (int i = l.Row + 1; i < r.Row; i++) {
                clipboard.push_back(data[i]);
            }
            clipboard.push_back(data[r.Row].substr(0, r.Col));
        }
    }
}
void TextEditor::paste() {
    if (selected) {
        del();
    }
    if (clipboard.empty()) {
        return;
    }
    if (clipboard.size() == 1u) {
        data[l.Row].insert(l.Col, clipboard[0]);
        l.Col += clipboard[0].size();
        return;
    }
    std::string str = data[l.Row];
    data[l.Row] = str.substr(0, l.Col) + clipboard.front();
    data.insert(data.begin() + l.Row + 1, clipboard.back() + str.substr(l.Col));
    for (int i = 1; i < (int)clipboard.size() - 1; i++) {
        data.insert(data.begin() + l.Row + i, clipboard[i]);
    }
    l.Row += (int)clipboard.size() - 1;
    l.Col = clipboard.back().size();
}
void TextEditor::screenShot() {
    for (int i = 0; i < (int)data.size(); i++) {
        if (i != l.Row && i != r.Row) {
            std::cout << data[i];
        } else {
            for (int j = 0; j < (int)data[i].size(); j++) {
                if (i == l.Row && j == l.Col) {
                    std::cout << '*';
                }
                if (i == r.Row && j == r.Col) {
                    std::cout << '*';
                }
                std::cout << data[i][j];
            }
            if (i == l.Row && (int)data[i].size() == l.Col) {
                std::cout << '*';
            }
            if (i == r.Row && (int)data[i].size() == r.Col) {
                std::cout << '*';
            }
        }
        if (i < (int)data.size() - 1) {
            std::cout << '\n';
        }
    }
}