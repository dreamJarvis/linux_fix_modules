const posts = [
    { title: 'Post One', body: 'This is post one' },
    { title: 'Post Two', body: 'This is post two' }
];

function getPosts() {
    setTimeout(() => {
        let output = '';
        posts.forEach((post, index) => {
            output += `<li>${post.title}</li> \n`;
        })
        console.log(output);
    }, 1000);
}


// ====================== callbacks ========================= //
// function createPosts(post, callback) {
//     setTimeout(() => {
//         posts.push(post);
//         callback();
//     }, 2000);
// }

// // getPosts();
// createPosts({ title: 'Post Three', body: 'This is post three' }, getPosts);
// createPosts({ title: 'Post Four', body: 'This is post Four' }, getPosts);
// createPosts({ title: 'Post Five', body: 'This is post Five' }, getPosts);
// createPosts({ title: 'Post Six', body: 'This is post six' }, getPosts);


// ref : https://www.youtube.com/watch?v=DHvZLI7Db8E
// ====================== Promises ====================== //
// const homeWorkDone = false;
// const wentToGym = true;

// --> here we have to rely on callback's 

// function schedule(callback, errorCallback) {
// if (homeWorkDone) {
//     errorCallback({
//         name: 'User',
//         message: 'Went to the gym'
//     });
// } else if (wentToGym) {
//     errorCallback({
//         name: 'User',
//         message: 'Doing Homework'
//     });
// } else {
//     callback('Get Work Done !');
// }
// }

// schedule((message) => {
//     console.log("User : ", message)
// }, (error) => {
//     console.log(error.name + ' ' + error.message);
// });

// // the whole idea of a promise is to avoid situations like these, where it no longer has to use callback
// const homeWorkDone = false;
// const wentToGym = true;

// function schedule() {
//     return new Promise((resolve, reject) => {
//         if (homeWorkDone) {
//             reject({
//                 name: 'User',
//                 message: 'Went to the gym'
//             });
//         } else if (wentToGym) {
//             reject({
//                 name: 'User',
//                 message: 'Doing Homework'
//             });
//         } else {
//             resolve('Get Work Done !');
//         }
//     });
// };

// schedule().then((message) => {
//     console.log("User : ", message)
// }).catch((error) => {
//     console.log(error.name + ' ' + error.message);
// });

// function createPosts(post) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             posts.push(post);
//             resolve(`${post.title}`);
//         }, 2000);
//     });
// }

// function createPostsII(post) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             posts.push(post);
//             resolve(`${post.title}`);
//         }, 6000);
//     });
// }

// getPosts();
// createPosts({ title: 'Post Three', body: 'This is post three' }).then((mes) => {
//     getPosts(posts);
// }).catch((error) => {
//     console.log("error detected");
// })

// createPosts({ title: 'Post Four', body: 'This is post Four' }).then((mes) => {
//     getPosts(posts);
// }).catch((error) => {
//     console.log("error detected");
// })


// // wait's until all the promise's are completed
// Promise.all([
//     createPosts({ title: 'Post Three', body: 'This is post three' }),
//     createPostsII({ title: 'Post Four', body: 'This is post Four' }),
//     createPosts({ title: 'Post Five', body: 'This is post Five' }),
//     // createPosts({ title: 'Post Six', body: 'This is post six' })
// ]).then((message) => {
//     console.log(message);
//     getPosts(posts);
// }).catch((err) => {
//     console.log("Error !");
// })

// createPosts({ title: 'Post Four', body: 'This is post Four' })
// createPosts({ title: 'Post Five', body: 'This is post Five' });
// createPosts({ title: 'Post Six', body: 'This is post six' });

// ======================= async Await ======================= //
function makeRequest(location) {
    return new Promise((resolve, reject) => {
        console.log(`Makeing Request to ${location}`);

        if (location === "Google") {
            resolve("Google says Hi !");
        } else {
            reject("We can only talk to google");
        }
    });
};

function processRequest(response) {
    return new Promise((resolve, reject) => {
        console.log("Processing response");
        resolve(`Extra information + ${response}`);
    });
}

// makeRequest("Facebook").then((response) => {
//     console.log("Response Recieved");
//     return processRequest(response);
// }).then(processRequest => {
//     console.log(processRequest);
// }).catch((err) => {
//     console.log(err);
// });


async function doWork() {
    try {
        const response = await makeRequest("Google");
        console.log("Response Recieved");
        const processResponse = await processRequest(response);
        console.log(processResponse);
    } catch (err) {
        console.log(err);
    }
}

doWork();