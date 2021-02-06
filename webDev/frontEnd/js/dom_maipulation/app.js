//--- Examine the document obeject ---//
// console.dir(document)

// console.log(document.domain);
// console.log(document.URL);
// console.log(document.title);
// console.log(document.doctype);
// console.log(document.head);
// console.log(document.body);
// console.log(document.all[10]);

// === selectors === //
// GET_ELEMENT_BY_ID
// const headerTitle = document.getElementById('header-title');
// const header = document.getElementById('main-header');
// headerTitle.textContent = 'hello';
// console.log(headerTitle.textContent);
// console.log(headerTitle.innerText);

// headerTitle.innerHTML = '<h3>Hello World !</h3>'
// console.log(headerTitle);
// header.style.borderBottom = 'solid 4px cyan';

// GET_ELEMENTS_BY_CLASS
// const items = document.getElementsByClassName('list-group-item');
// // console.log(items);
// // console.log(items[1]);
// items[1].textContent = 'HeLLo wOrLd.....!';
// items[1].style.fontWeight = 'bold';
// // items[1].style.color = 'white';
// items[1].style.backgroundColor = 'magenta';

// for(let i = 0; i < items.length; i++){
//     items[i].style.backgroundColor = '#f4f4f4';
// }

// === query selectors === //
// let header = document.querySelector('#main-header');
// header.style.borderBottom = 'solid 4px cyan';

// const input = document.querySelector('input');
// input.value = 'hello world';

// const button = document.querySelector('input[type="submit"]');
// button.style.backgroundColor = '#D45f';

// const item = document.querySelector('.list-group-item');
// item.style.color = 'red';

// const itemLast = document.querySelector('.list-group-item:last-child');
// itemLast.style.color = 'magenta';

// const nthItem = document.querySelector('.list-group-item:nth-child(3)');
// nthItem.style.color = 'blue';

// Qurey Selector All //
// const titles = document.querySelectorAll('.title');
// const odd = document.querySelectorAll('li:nth-child(odd');

// // can use forEach on nodeList but not on HTMLCollections
// odd.forEach(e=>{
//     e.style.backgroundColor = '#f4f4f4';
// })
// // console.log(titles);

// === Traversing the DOM === //
// const itemList = document.querySelector('#items');

// == parentNode == //
// console.log(itemList.parentNode);
// itemList.parentNode.style.backgroundColor = '#f4f4f4';

// == parentElement == //
// itemList.parentElement.style.backgroundColor = '#f4f4f4';

// == childNodes == //
// console.log(itemList.childNodes);

// childern
// console.log(itemList.children);
// let child = itemList.children;
// for(let i = 0; i < child.length; i++)
//     child[i].style.backgroundColor = '#f4f4f4';

// console.log(itemList.firstElementChild);
// itemList.firstElementChild.textContent = 'Heelo World !';
// itemList.lastElementChild.textContent = 'Bye World !';

// siblings
// const itemList = document.querySelector('.title');
// console.log(itemList.nextSibling);
// console.log(itemList.nextElementSibling);
// itemList.nextElementSibling.firstElementChild.style.backgroundColor = '#f4f4f4';
// // itemList.previousElementSibling.style.fontWeight = 'bold';
// console.log(itemList.previousElementSibling);

// // createElement
// let newDiv = document.createElement('div');

// newDiv.className = 'hello';                 // add class
// newDiv.id = 'helo1'                         // add id
// newDiv.setAttribute('title', 'HelloDiv');   // add attribute
    
// let newDivText = document.createTextNode('Hello world');

// newDiv.appendChild(newDivText);
// console.log(newDiv);

// const container = document.querySelector('header .container');
// const h1 = document.querySelector('header h1');

// // insert newDiv before h1
// newDiv.style.fontSize = '16px';
// container.insertBefore(newDiv, h1);


// events
// const button = document.getElementById('button');
// button.addEventListener('click', function(e){
//     document.querySelector('#main').style.backgroundColor = '#f4f4f4';
//     // console.log(e);
//     // console.log(e.target);
//     // console.log(e.target.id);
//     // console.log(e.target.className);
//     // console.log(e.target.classList);
//     // console.log(e.type);
//     console.log("x : ", e.clientX, ", y : ", e.clientY);
// });

// var box = document.getElementById('box');
// box.addEventListener('mousemove', runEvent);
// box.addEventListener('mouseleave', runEventII);

// function runEvent(e){
//     box.style.backgroundColor = "rgb("+e.offsetX+", "+e.offsetY+", 40)";
//     document.body.style.backgroundColor = "rgb("+e.offsetX+", "+e.offsetY+", 40)";
// }
/*
    key events :

    keydown, keyup
    focus, blur
    cut, paste
    input
*/

// function runEventII(e){
//     box.style.backgroundColor = "#f4f4f4";
//     document.body.style.backgroundColor = "#f4f4f4";
// }

const itemInput = document.querySelector('input[type="text"]');
const form = document.querySelector('form');

form.addEventListener('submit', runEvent);

function runEvent(e){
    e.preventDefault();
    let list = document.querySelector('#items');
    let newLi = document.createElement('li');
    newLi.className = 'list-group-item';

    const newText = document.createTextNode(`${itemInput.value}`);
    newLi.appendChild(newText);
    list.appendChild(newLi);

    itemInput.value = "";
}

// document.querySelector('select').addEventListener('change', (e)=>{
//     console.log(e.type);
//     console.log(e.target.value);
// })