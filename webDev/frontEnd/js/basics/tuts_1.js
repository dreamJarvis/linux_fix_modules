// console.log('hello world !');

// variables : let, const
// let age = 12;
// const name = "tarun";
// const age = 22;
// console.log(age);

// const id = 12312;
// console.log(id);

// console.log(`My name is ${name} and i am ${age}`)
 
// const s = "tech, computers, it, code";
// const a = s.split(', ');

// const names = new Array('Tarun', 'Manav');

// const fruits = ["aaples", "oranges"];
// fruits[2] = "grapes";
// fruits.push("mangoes");
// fruits.pop();
// fruits.unshift("berries");

// console.log(names, fruits);
// console.log(Array.isArray(fruits));

// console.log(fruits);

// const person = {
//     firstName : 'Tarun',
//     lastName : 'Jha',
//     aeg : '22',
//     hobbies : ['music', 'art','movies'],
//     address : {
//         street : "rx-4b/266",
//         city : 'New Delhi',
//         state : 'Delhi'
//     }
// }

// console.log(person);

// const { firstName, lastName } = person;     // destructuring
// console.log(firstName);

// person.email = "Tarun@gmail.com";
// console.log(person);

// const todos = [
//     {
//         id : 1,
//         text : 'complete hw',
//         isComplete : true
//     },
//     {
//         id : 2,
//         text : 'do laundry',
//         isComplete : false
//     },
//     {
//         id : 3,
//         text : 'water plants',
//         isComplete : true
//     }
// ];

// console.log(todos);

// const todosJSON = JSON.stringify(todos);
// console.log(todosJSON);

// for loops
// for(let i=0; i < todos.length; i++)
//     console.log(todos[i].text);

// for(let todo of todos)
//     console.log(todo.text);

// // for each
// todos.forEach(function(todo){
//     console.log(todo.text);
// });

// // map
// const todosText = todos.map(function(todo){
//     return todo.text;
// });
// console.log(todosText);

// // filter
// const todosCompleted = todos.filter(function(todo){
//     return todo.isComplete === true;
// }).map(function(todo) {
//     return todo.text;
// })

// console.log(todosCompleted);

// OOPS

// function Person(firstName, lastName, dob){
//     this.firstName = firstName;
//     this.lastName = lastName;
//     this.dob = new Date(dob);
// }

// // prototyping functions
// Person.prototype.getBirthYear = function(){
//     return this.dob.getUTCFullYear();
// }

// Person.prototype.getFullname = function(){
//     return `${this.firstName} ${this.lastName}`;
// }

// const person1 = new Person('Tarun', 'Jha', '11-22-1998');
// // console.log(person1.dob.getDay()); 

// console.log(person1.getBirthYear());
// console.log(person1.getFullname());

// // class
// class Person {
//     constructor(firstName, lastName, dob){
//         this.firstName = firstName;
//         this.lastName = lastName;
//         this.dob = new Date(dob);
//     }


//     // getter functions
//     getBithYear() {
//         return this.dob.getFullYear();
//     }

//     getFullName() {
//         return `${this.firstName} ${this.lastName}`;
//     }
// }

// const person1 = new Person('Tarun', 'jha', '11-22-1998');
// console.log(person1.getBithYear());
// console.log(person1.getFullName());