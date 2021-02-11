#ifndef headers_H_
#define headers_H_

struct List* Create_List();

struct Item* Insert(char, int, struct Item*, struct List*);

int Compare(struct Item*, struct Item*, int);

void Show_Delete(struct List*);

#endif // !HEADERS_H_
