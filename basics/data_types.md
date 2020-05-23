### auto
`auto`表示变量类型自动推断，例如
```
int a = 10;
auto au_a = a;//自动推断出au_a的类型为int
cout << typeid(au_a).name() << endl; // output "int".
```
### bool
+ `boolean leftVailid = true;` or `boolean leftVailid = false;`
+ `false`
  + `false`-equivalent: `NULL`, empty container (e.g. `int a;` then `a` is an empty container.), `0`
+ `true`
### char and string
+ `char a='p'`
+ `string a="good"`
+ wrong definition `char a="p"`, `string a='good'`
