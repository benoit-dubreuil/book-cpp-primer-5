# Notes

- Une référence n'est pas un objet, c'est un alias, contrairement à un pointeur, d'où le fait qu'on ne peut pas changer l'objet pointé par celle-ci. De toute façon, ça rendrait impossible la fonctionnalité d'alias. Parce qu'une référence n'est pas un objet, elle n'a donc pas d'adresse, d'où le fait qu'on ne peut pas assigner à un pointeur l'adresse d'une référence.
- Utiliser un pointeur non-défini dans un condition résulte en une undefined behavior.
- Lire le type d'un objet à partir de son nom de droite à gauche.
- Constexpr s'applique toujours au type le plus proche de la variable.
- `auto` ordinarily ignores top-level consts, à moins que ce soit un `auto &`.
- For constructors, when we use curly braces, {...}, we’re saying that, if possible, we want to list initialize the object. That is, if there is a way to use the values inside the curly braces as a list of element initializers, the class will do so. Only if it is not possible to list initialize the object will the other ways to initialize the object be considered.
- The `*` operator on an array is equivalent to `&array[0]`.
- Roughly speaking, when we use an object as an rvalue, we use the object’s value (its contents). When we use an object as an lvalue, we use the object’s identity (its location in memory).
- There are four operators that do guarantee the order in which operands are evaluated. The logical AND `&&` operator guarantees that its left-hand operand is evaluated first. Moreover, we are also guaranteed that the right-hand operand is evaluated only if the left-hand operand is true. The only other operators that guarantee the order in which operands are evaluated are the logical OR ``||`` operator, the conditional `? :` operator, and the comma `,` operator.
- For operators that do not specify **evaluation order**, it is an error for an expression to refer to and change the same object. Expressions that do so have undefined behavior.
Order of operand evaluation is independent of precedence and associativity. In an expression such as f() + g() * h() + j():
	- **Precedence** guarantees that the results of g() and h() are multiplied.
	- **Associativity** guarantees that the result of f() is added to the product of g() and h() and that the result of that addition is added to the value of j().
	- There are no guarantees as to the order in which these functions are called.
- It is usually a bad idea to use the boolean literals true and false as operands in a comparison. These literals should be used only to compare to an object of type bool.
`if (val == true) { /* ... */ }` is equivalent to
`if (val == 1) { /* ... */ }`.
- If the operand is signed and its value is negative, then the way that the “sign bit” is handled in a number of the bitwise operations is machine dependent. Moreover, doing a left shift that changes the value of the sign bit is undefined.
- The `sizeof` operator is unusual in that it does not evaluate its operand.
- The result of a **comma expression** is the value of its right-hand expression. The left-hand expression is evaluated and its result is discarded.
- `const_cast` : If the object was originally not a const, using a cast to obtain write access is legal. However, using a const_cast in order to write to a const object is undefined.
- A `reinterpret_cast` is inherently machine dependent. Safely using `reinterpret_cast` requires completely understanding the types involved as well as the details of how the compiler implements the cast.
- Precedence determines how operators are grouped in a compound expression.
- Associativity determines how operators at the same precedence level are grouped.
- Label identifiers are independent of names used for variables and other identifiers (`goto`).
- In C++, names have scope, and objects have lifetimes.
- If a local static has no explicit initializer, it is value initialized, meaning that local statics of built-in type are initialized to zero.
- ```
  // each function has a single parameter of type const int*
  void print(const int*);
  void print(const int[]); // shows the intent that the function takes an array
  void print(const int[10]); // dimension for documentation purposes (at best)
  ```
- Ellipsis parameters are in C++ to allow programs to interface to C code that uses a C library facility named `varargs`. Generally an ellipsis parameter should not be used for other purposes.
- Calls to functions that return references are lvalues; other return types yield rvalues.
- Only use the `explict` keyword on constructors with only one parameter (unary constructors).
- The behavior of `assert` depends on the status of a preprocessor variable named `NDEBUG`. If `NDEBUG` is defined, `assert` does nothing. By default, `NDEBUG` is not defined, so, by default, `assert` performs a run-time check. `NDEBUG` = not debug.
- Casts should not be needed to call an overloaded function. The need for a cast suggests that the parameter sets are designed poorly.
- Function types are automatically converted to pointers, for the same reasons as arrays, for variable types and parameter types but not for return types. So, function return types must be specifically declared as pointers.
- The `explicit` keyword is meaningful only on constructors that can be called with a single argument. Constructors that require more arguments are not used to perform an implicit conversion, so there is no need to designate such constructors as `explicit`.
- After a move operation, the “moved-from” object must remain a valid, destructible object but users may make no assumptions about its value.
- Un `&` à la fin d'une déclaration de fonction member dicte qu'elle ne peut être appliquée que sur une `lvalue`, tandis qu'un `&&` à la fin d'une déclaration de fonction member dicte qu'elle ne peut être appliquée que sur une `rvalue`. Le `const` à la fin d'une déclaration de fonction membre vient avant le `&` et le `&&`.
- Ordinarily, the comma, address-of, logical AND, and logical OR operators should not be overloaded.
- Generally, output operators should print the contents of the object, with minimal formatting. They should not print a newline.
- Conversion to bool is usually intended for use in conditions. As a result, operator bool ordinarily should be defined as explicit.
- A function that is declared as `virtual` in the base class is implicitly `virtual` in the derived classes as well.
- Virtual functions that have default arguments should use the same argument values in the base and derived classes.
- If a constructor or destructor calls a virtual function, the version that is run is the one corresponding to the type of the constructor or destructor itself.
- An argument of any type can be passed to a function parameter that is an rvalue reference to a template parameter type (i.e., `T&&`). When an lvalue is passed to such a parameter, the function parameter is instantiated as an ordinary, lvalue reference (`T&`).
- A function parameter that is an rvalue reference to a template type parameter (i.e., `T&&`) preserves the constness and lvalue/rvalue property of its corresponding argument.
- When used with a function parameter that is an rvalue reference to template type parameter (`T&&`), `forward` preserves all the details about an argument’s type.
- Ordinarily, a `catch` that takes an exception of a type related by inheritance ought to define its parameter as a reference.
- Multiple `catch` clauses with types related by inheritance must be ordered from most derived type to least derived.
- `noexcept` has two meanings: It is an exception specifier when it follows a function’s parameter list, and it is an operator that is often used as the `bool` argument to a `noexcept` exception specifier.
- Unlike other namespaces, an unnamed namespace is local to a particular file and never spans multiple files.
- The use of file `static` declarations is deprecated by the C++ standard. File statics should be avoided and unnamed namespaces used instead.
- Virtual base classes are always constructed prior to nonvirtual base classes regardless of where they appear in the inheritance hierarchy.
- Do not use `union`s for type punning as it is an undefined behaviour.
- Ordinarily it is best to make a bit-field an `unsigned` type. The behavior of bit-fields stored in a `signed` type is implementation defined.
- The precise meaning of `volatile` is inherently machine dependent and can be understood only by reading the compiler documentation. Programs that use `volatile` usually must be changed when they are moved to new machines or compilers.
