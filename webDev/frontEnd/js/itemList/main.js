const form = document.querySelector('form');
const itemInput = document.querySelector('#item');
const list = document.querySelector('#items');
const filter = document.querySelector('#filter');

// action taken when form is submitted
form.addEventListener('submit', onSubmit);
function onSubmit(e){
    e.preventDefault();

    // creating new li
    const newLi = document.createElement('li');
    const newText = document.createTextNode(`${itemInput.value}`);

    // creating new delete button
    const newButton = document.createElement('button');
    newButton.className = document.querySelector('li').children[0].className;
    newButton.innerText = 'X';

    // appeding the button and text to new li
    newLi.className = 'list-group-item';
    newLi.appendChild(newText);
    newLi.appendChild(newButton);

    // appeding the li to the list
    list.appendChild(newLi);

    itemInput.value = "";
}

// to delete an item from the item list
list.addEventListener('click', removeItem);
function removeItem(e){
    if(e.target.classList.contains('delete')){
        if(confirm('Are you sure ?')){
            let li = e.target.parentElement;
            list.removeChild(li);
        }
    }
}

// filter elements
filter.addEventListener('keyup', filterItem);
function filterItem(e){
    let text = e.target.value.toLowerCase();
    let items = list.getElementsByTagName('li');        // HTML collections

    // convert HTML Collections to array 
    // and search for text in the list of li containing text's
    Array.from(items).forEach(function(item){
        let itemName = item.firstChild.textContent;

        if(itemName.toLowerCase().indexOf(text) != -1)
            item.style.display = 'block';
        else
            item.style.display = 'none';
    });
}