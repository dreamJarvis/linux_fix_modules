const userInput = document.querySelector('#userInput > button');
const input = document.querySelector('input');
const itemList  = document.querySelector('#items');

// adding element to the list
userInput.addEventListener('click', (e) => {
    const newLi = document.createElement('li');
    newLi.className = 'list-group-item item';

    const newSpan = document.createElement('span');
    newSpan.innerText = input.value;

    const addButton = document.createElement('button');
    addButton.className = 'btn btn-danger pull-right delete';
    addButton.style.marginTop = '-6px';
    addButton.innerText = 'X';

    newLi.appendChild(newSpan);
    newLi.appendChild(addButton);
    itemList.appendChild(newLi);

    input.value = "";
});

// deleting element from the list
itemList.addEventListener('click', (e) => {
    if(e.target.classList.contains('delete')){
        let li = e.target.parentElement;
        itemList.removeChild(li);
    }
});

// console.log(itemList);