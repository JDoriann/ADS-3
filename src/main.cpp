// Copyright 2021 NNTU-CS

#include <string>
#include "tstack.h"

int Sym(char z) {
if((z == '/')||(z == '*')) {
return 3;
} else if((z == '+')||(z == '-')) {
return 2;
} else if(z == ')') {
return 1;
} else if(z == '(') {
return 0;
} else {
return -1;
}
}

std::string infx2pstfx(std::string inf) {
TStack<char> inf1;
int i = 0;
int j = 0;
std::string inf2;
std::string inf3;
char t = 0;
char t2 = 0;
char t3 = 0;

while(i < inf.size()) {
if(Sym(inf[i]) == -1) {
inf1.push(inf[i]);
i++;
} else if((Sym(inf[i]) == 3) || (Sym(inf[i]) == 2)) {
if(Sym(inf[i + 1]) != 0) {
t = inf[i];
i++;
} else {
if((Sym(inf[i-3]) == 1) && (Sym(inf[i-2]) == 3)) {
t3 = inf[i];
i++;
} else {
t2 = inf[i];
i++;
}
}
} else if(Sym(inf[i]) == 0) {
i++;
while(Sym(inf[i]) != 1) {
if(Sym(inf[i]) == -1) {
inf1.push(inf[i]);
i++;
} else if((Sym(inf[i]) == 3) || (Sym(inf[i]) == 2)) {
t = inf[i];
i++;
}
}
if(Sym(inf[i]) == 1) {
inf1.push(t);
t = 0;
i++;
}
if(t2 != 0) {
inf1.push(t2);
t2 = 0;
}
}
if((t != 0) && (Sym(inf[i]) == -1)) {
inf1.push(inf[i]);
inf1.push(t);
t = 0;
i++;
}
}
if(t3 != 0) {
inf1.push(t3);
}
while(inf1.isEmpty() == false) {
inf2 += inf1.get();
inf1.pop();
}
j = inf2.size() - 1;
while(j > -1) {
inf3 += inf2[j];
if(j) {
inf3 += ' ';
}
j--;
}
return inf3;
}

int eval(std::string pst) {
TStack<std::string> stack1;
int result = 0;    
std::string t;
int j = 0;
int a;
int b;

while(j < pst.size()) {
if((Sym(pst[j]) == -1) && (pst[j+1] == ' ')) {
t = pst[j];
stack1.push(t);
j += 2;
} else if((Sym(pst[j]) == -1) && (Sym(pst[j+1]) == -1)) {
t = pst[j]+pst[j + 1];
stack1.push(t); 
j += 2;
} else if(pst[j] == '+') {
a = 0;
for(int m = 0; m < 2; m++) {
a += atoi(stack1.get().c_str());
stack1.pop();
}
t = std::to_string(a);
stack1.push(t);
j += 2;
} else if(pst[j] == '-') {
a = 0;
b = 0;
b = atoi(stack1.get().c_str());
stack1.pop();
a = atoi(stack1.get().c_str());
stack1.pop();
a -= b;
t = std::to_string(a);
stack1.push(t);
j += 2;
} else if(pst[j] == '*') {
a = 1;
for(int m = 0;m < 2; m++) {
a *= atoi(stack1.get().c_str());
stack1.pop();
}
t = std::to_string(a);
stack1.push(t);
j += 2;
} else if(pst[j] == '/') {
a = 0;
b = 0;
b = atoi(stack1.get().c_str());
stack1.pop();
a = atoi(stack1.get().c_str());
stack1.pop();
a /= b;
t = std::to_string(a);
stack1.push(t);
j += 2;
}
}
result = atoi(stack1.get().c_str());
return result;
}
