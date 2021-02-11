#ifndef headers_H_
#define headers_H_

typedef struct Item 
{
	char data;
	struct Item* left;
	struct Item* right;
	struct Item* up;
	struct Item* down;
} Item;

typedef struct List
{
	struct Item* first;
	struct Item* last;
} List;


struct List* Create(int);

int Print(struct List*);

void Delete(struct List*);

void Down(struct List*);

void Right(struct List*);

void Left(struct List*);

void Player(struct List*);

//void Score(struct List*);

//void Die(struct List*, struct Item*);

void Bomb(struct List*);

int Bomb_Move(struct List*);

int Comb(struct List*);

int Play_Record();

#endif // !HEADERS_H_
