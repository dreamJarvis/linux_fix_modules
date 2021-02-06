// console.log(window);

// const items = document.querySelectorAll('.item');
// items.forEach((item) => console.log(item));

// const ul = document.querySelector('.items');
// // ul.remove();
// // ul.lastElementChild.remove();
// ul.firstElementChild.textContent = 'Hello';
// ul.children[1].innerText = 'Tarun';
// ul.lastElementChild.innerHTML = '<h1>Hello World!</h1>';

// const btn = document.querySelector('.btn');
// // btn.style.background = 'red';

// let flag = true;
// btn.addEventListener('click', (e)=>{
//     e.preventDefault();

//     document.querySelector('#my-form').style.background = '#ccc';
//     document.querySelector('body').classList.add('bg-dark');

//     if(flag)    btn.style.background = 'red';
//     else        btn.style.background = '#333';
    
//     flag = !flag;
// }); 
 
const myForm = document.querySelector('#my-form');
const nameInput = document.querySelector('#name');
const emailInput = document.querySelector('#email');
const msg = document.querySelector('.msg');
const userList = document.querySelector('#users');

myForm.addEventListener('submit', onSubmit);

function onSubmit(e){
    e.preventDefault();

    if(nameInput.value === '' || emailInput.value === ''){
        msg.classList.add('error');
        msg.innerHTML = 'Please enter all fields';

        setTimeout(() => msg.remove(), 3000);
    }else{
        const li = document.createElement('li');
        li.appendChild(
            document.createTextNode(
                `${nameInput.value} : ${emailInput.value}`
            )
        );
        userList.appendChild(li);

        // clear fields
        nameInput.value = '';
        emailInput.value = '';
    }
}