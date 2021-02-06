const formContainer = document.querySelector('form');
const taskContainer = document.querySelector('#textContainer');
let counter = 1;

class UI {
    static displayTasks() {
        const tasks = Storage.getTasks();
        tasks.forEach((task) => UI.addTaskToList(task));
    }

    static addTaskToList(task) {
        const newEle = document.createElement('tr');
        newEle.innerHTML = `
            <th scope="row">${counter}</th>
            <td style="text-align: center;">${task}</td>
            <td>
                <button type="button" class="btn btn-danger btn-sm float-right delete">X</button>
            </td>
        `;
        taskContainer.appendChild(newEle);
        counter++;
    }

    static deleteTask(task) {
        if (task.classList.contains('delete')) {
            task.parentElement.parentElement.remove();
        }
    }

    static clearFields() {
        document.querySelector('#taskText').value = "";
    }
};

// adding it to the local storage
// all the tasks is sotred here in the local storge
class Storage {
    static getTasks() {
        let tasks;
        if (localStorage.getItem('tasks') === null) {
            tasks = [];
        } else {
            tasks = JSON.parse(localStorage.getItem('tasks'));
        }

        return tasks;
    }

    static addTask(task) {
        const tasks = Storage.getTasks();
        tasks.push(task);
        localStorage.setItem('tasks', JSON.stringify(tasks));
    }

    static removeTask(task) {
        let tasks = Storage.getTasks();
        tasks.forEach((e, index) => {
            if (e === task) {
                console.log(e);
                tasks.splice(index, 1);
            }
        });

        // update the storage array
        localStorage.setItem('tasks', JSON.stringify(tasks));
    }
};

// event : to display all the items in the local storage
document.addEventListener('DOMContentLoaded', UI.displayTasks);

// event : to add a task
formContainer.addEventListener('submit', (e) => {
    e.preventDefault();
    const task = document.querySelector('#taskText').value;

    // validate
    if (task === '') {
        console.log("fill the details");
    } else {
        UI.addTaskToList(task);
        Storage.addTask(task);
        UI.clearFields();
    }
});

// event : remove a book
taskContainer.addEventListener('click', (e) => {
    UI.deleteTask(e.target);
    Storage.removeTask(e.target.parentElement.previousElementSibling.textContent);
    // console.log(e.target.parentElement.previousElementSibling.textContent);
});