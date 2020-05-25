# bruh-lang
bruh-lang, my own programming language - because everyone needs to make one, once in a lifetime, right?

## Description

bruh-lang will be
* Statically-typed: everything should have one, proper type, and possibly be checked by interpreter/compiled.
* Mixed-paradigm: functional and object-oriented, similar to C++ and Rust
* Memory-aware: i don't know if something like that even exist, but the point is that it will manage the memory allocation by itself on pre-allocated memory blocks. We'll see.
* Transpilled: to C i suppose. I dunno, i'll see. I need to make interpreter first and see if this will work out as i expect.
* Expression-based: in other word, everything there will be an expression.

Generally, my goal is to make a decently feature-rich language runnable on microcontrollers. Therefore, i've decided the best way to do it will be by transpilling it to C and compiling with existing tools.

For now, i'm gonna try to create a simple interpreter, syntax, and basic stuff. Then, we'll see how far it will go.

### Why microcontrollers?

Because i think that C is not enough, and C++ is too much. Yeah, there is Rust - and i could use it and learn it, but i need (another) side project to work on in free time so i don't get crazy.
C is fine, but writing anything large can be painful because of the *simplicity* of this language. I want more tools, but i can't get them easely.

And yes, creating entirely new language from scratch *is* an overkill. Don't do it kids.

## Syntax - what i aim for

### Hello, world!

```
func main() > int {
  print("hey there");

  return 0;
}
```

I've decided to keep C-like function syntax. I'm used to it. Many people are familiar with it.
Return is implicit, by default function returns default-constructed value.

And yes, return type is specified after function declaration, with `>` char.

Interpreter executes code just like it would be in `main` function.

### Variables and constants

```
const some_constant = 10;
const explicitly_typed_constant = int(10);
var the_variable = 1234;
var another_variable = 3.14;
var a_string = "this is a test";
var heres_array = array[int] {3, 4, 5};
var[int] explicitly_typed_variable;
```

There are variables, and there are constants. I strongly recommend using the latter by default. I'm not gonna force you to do it, like Rust does, but i'm gonna put it everywhere i possibly can.

You declare a variable using `var` keyword. You declare a constant using `const` keyword. Simple, right?

You can explicitly tell the type by putting it into the `[]` right after `var` or `const`.
Then, you name it. Standard rules: name can be made of a-z A-Z 0-9 and _. Cannot start with a number.
Then, you set a value. If you won't, it will be initialized with default value. If, for some reason, you have a type that cannot have default value, make sure it's nullable (i'll get into it soon).

If you won't set a type explicitly, it will be deduced from initializer, or throw an error if it's not possible to do.

### Types

Some types i want to have:

* `int` - basic integer, 32-bit, nothing special here
* `bigint` - big integer, 64-bit.
* `smallint` - small integer, 16-bit
* `byte` - a single byte, 8-bit
* `float` - floating-point number. The 32-bit one. The small one.
* `double` - another floating-point number. The 64-bit one. The good one. Prefer it, unless you need his little brother.

First 4 of these are also available as unsigned versions, with `u` prefix: `uint`, `ubigint`, `usmallint`, `ubyte`

We also have

* `char` - character. Yes, it will be 8-bit long, i'm not going to support UTF just yet. *What's the difference from byte then?* Type safety and explicity.
* `bool` - of course
* `void` - no value. Nothing. Nada. *Will there be `none`?* Nope. I'm not creating another JavaScript. The only value `void` can have is `null`.
* `ptr` - there will be a pointer type, don't worry.
* `ref` - and also reference type. Yeah, i'm just copying C++ at this point.

The `ptr` and `ref` are, in the matter of fact, `sub-types`, because every type can be a reference and pointer type, just like in C and C++.

### Operators

Basic set of standard operators, for now
* `+`, `-`, `/`, `*`, `**` - add, sub, div, mul, pow
* `^`, `&`, `|`, `~` - xor, and, or, not - bitwise
* `and`, `or`, `not` - logical operators
* `==`, `!=`, `<`, `>`, `<=`, `>=` - equal, not equal, less than, greater than, less or equal, greater or equal
* `:` - namespace access
* `@` - pointer access (*at* is pretty reasonable i think). Think of `*`, but making an actual sense.
* `&` - reference access (yeah, C once again)
* `++`, `--` - increment, decrement

that's it for now, maybe when i'll think about something new i'll add it.

### Expressions

Ever heard the sentence *everything is an expression*? Now you did.

Yeah, every single thing here can return a value. If it explicitly does not, it just returns `null`. However, i think that's pretty fun design choice that allows a lot of flexibility for programmer.

So, every block can return a thing, every conditional instruction and loop can return a thing, and so on. Keep that in mind, i'll explain everything later. I hope.

### Flow control

#### Conditional instructions

boring old stuff

```
if something then {
  do stuff
} else {
  do other stuff
}
```

and yeah, `else` can be chained with another `if` to create `else if`.

```
check value {
  if some_value then {
    do stuff
  }
  if other_value then {
    do other stuff
  }
} else {
  do stuff if it's not any of checked values
}
```

okay, that's kinda different. It's a `switch-case`, but a little modified to make it a little bit more understandable in my taste.
also, `case default` looks nasty in my opinion, i think that this `else` is a bit more clear.

#### Loops

```
while condition {
  do stuff
}
```

nothing new here, plain old `while`

```
do {
  do things
} while(condition)
```

same as above but with at least one iteration

```
for var x = 0 while x < 10 end x++ {
  wololo
};
```

that's a change. See, i like verbosity. A lot. This works just like good ol' C-style `for` loop, except it has keywords instead of `;`.

and yes, it can iterate over a container:
```
for item in container {
  do things
};
```

*btw, you can also put `end` thing there if you want*

### Functions

```
func do_stuff(int first_arg, bool second_arg, ref float third_arg) > string {

}
```

nothing fancy here. `func` indicates that it's a function, `do_stuff` is the name, arguments in parenthesis, separated by commas.
Oh, yeah, the return type is after arguments, after `>` thing.

#### Anonymous functions

Yeah, the fancier ones.

```
const hi = func() { print("hi"); };
```

Maybe i'll add capturing the environment to make them real closures later.

### Structures

You kids seen Rust? I like how they managed to merge classes and structures. So i'm going to take similar approach.
There will be a `struct` type which will allow to create POD's only (*Plain Old Data*, basically a container for stuff without any logic attached)
You will be able to implement the methods for this `struct` easely thought, and call them just like class methods in most languages.

```
struct SomeData {
  int field;
  float other_field;
  string wololo;
}

extend SomeData {
  func create(int value) {
    field = value * 2;
  }
}
```

## Standard library

Yeah, there will be something.
Pretty sure i'll have an `array` type, you've seen example of declaration above. It will have index-based access, both safe and unsafe, and some utility methods. It'll be closer in usage to `std::array` than c-style array - i hate those.
And there will be `string`, which will be just a fancy `array` for chars. A little bit more verbose i suppose.

I'll also try to provide some basic functions, I/O, and stuff. We'll see.