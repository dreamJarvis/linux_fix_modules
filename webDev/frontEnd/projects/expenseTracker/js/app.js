class Item{
    constructor(itemName, cost, date){
        this.itemName = itemName;
        this.cost = cost;
        this.date = date;
    }
};

class UI{
    static displayItems(){
        // const StoredItems = [
        //     {
        //         itemName: 'Milk',
        //         cost: '30',
        //         date: '4-12-2020'
        //     },
        //     {
        //         itemName: 'Bread',
        //         cost: '35',
        //         date: '6-12-2020'
        //     }
        // ];

        // const items = StoredItems;
        // items.forEach((item) => UI.addItemToList(item));
        const items = Store.getItems();
        items.forEach((item) => UI.addItemToList(item));
        UI.totalExpense();
    }

    // add item to list
    static addItemToList(item){
        const list = document.querySelector('#item-list');

        const row = document.createElement('tr');       // this is the parent element we re deleting
        row.innerHTML = `
            <td>${item.itemName}</td>
            <td class="cost">${item.cost}</td>
            <td>${item.date}</td>
            <td><a href="#" class="btn btn-danger btn-sm delete">X</td>
        `;

        list.appendChild(row);
    }

    // remove item from the list
    static removeItem(e){
        if(e.classList.contains('delete')){
            // console.log(e.parentElement.parentElement);
            e.parentElement.parentElement.remove();
        }
    }

    // clear values from the field's 
    static clearValues(){
        document.querySelector('#itemName').value = "";
        document.querySelector('#cost').value = "";
        document.querySelector('#date').value = "";
    }

    // shows total expense
    static totalExpense(){
        const list = document.querySelectorAll('.cost');
        console.log(list);

        let totalExpense = 0;
        list.forEach((item) => {
            totalExpense += parseInt(item.textContent);
        });

        console.log(totalExpense);

        document.querySelector('#sum-Cost').innerHTML = `<span>${totalExpense}</span>`;;
    }
}

class Store{
    static getItems(){
        let items;
        if(localStorage.getItem('items') === null){      // local storage is empty
            items = [];
        }
        else{
            items = JSON.parse(localStorage.getItem('items'));
        }
        
        return items;
    }

    static addItem(item){
        const items = Store.getItems();
        items.push(item);
        localStorage.setItem('items', JSON.stringify(items));
    }

    // removing item according to their date and cost
    static removeItem(item){
        const itemName = item[0].innerHTML;
        const cost = item[1].innerHTML;
        const date = item[2].innerHTML;

        const items = Store.getItems();
        items.forEach((currItem, index) => {
            if(currItem.itemName === itemName && currItem.date === date){
                items.splice(index, 1);
            }
        });

        // update the array in the local storage
        localStorage.setItem('items', JSON.stringify(items));
        UI.totalExpense()
    }
};

// load content to the page
document.addEventListener('DOMContentLoaded', UI.displayItems());

// add item to list
document.querySelector('#item-form').addEventListener('submit', (e) => {
    e.preventDefault();

    const itemName = document.querySelector('#itemName').value;
    const cost = document.querySelector('#cost').value;
    const date = document.querySelector('#date').value;

    const item = new Item(itemName, cost, date);
    UI.clearValues();
    UI.addItemToList(item);
    Store.addItem(item);
    UI.totalExpense();
});

// remove item from list
document.querySelector('#item-list').addEventListener('click', (e) => {
    UI.removeItem(e.target);
    console.log(e.target.parentElement.parentElement.children);
    Store.removeItem(
        e.target.parentElement.parentElement.children
    );
});