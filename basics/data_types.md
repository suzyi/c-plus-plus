### auto
`auto`表示变量类型自动推断，例如
```
int a = 10;
auto au_a = a;//自动推断出au_a的类型为int
cout << typeid(au_a).name() << endl; // output "int".
```
