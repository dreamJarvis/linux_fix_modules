// console.log("Hello");
const companies = [
    { name: "Company One", category: "Finance", start: 1981, end: 2003 },
    { name: "Company Two", category: "Retail", start: 1992, end: 2008 },
    { name: "Company Three", category: "Auto", start: 1999, end: 2007 },
    { name: "Company Four", category: "Retail", start: 1989, end: 2010 },
    { name: "Company Five", category: "Technology", start: 2009, end: 2014 },
    { name: "Company Six", category: "Finance", start: 1987, end: 2010 },
    { name: "Company Seven", category: "Auto", start: 1986, end: 1996 },
    { name: "Company Eight", category: "Technology", start: 2011, end: 2016 },
    { name: "Company Nine", category: "Retail", start: 1981, end: 1989 }
];

const ages = [33, 12, 20, 16, 5, 54, 21, 44, 61, 13, 15, 45, 25, 64, 32];

// simple for-loop
// for (let i = 0; i < companies.length; i++)
//     console.log(companies[i]);

// for-each loop
// companies.forEach(function(company, index) {
//     console.log(company.name);
// });

// ===================  filter ================= //
// filter ages over 21
// // using for loop
// let canDrink = [];
// for (let i = 0; i < ages.length; i++) {
//     if (ages[i] >= 21) {
//         canDrink.push(ages[i]);
//     }
// }

// console.log(canDrink);

// using filter 
// const canDrink = ages.filter(function(age) {
//     if (age >= 21)
//         return true;
// });

// const canDrink = ages.filter(age => (age >= 21));
// console.log(canDrink);

// filter our retail companies
// const retialCompanies = companies.filter(company => (company.category === "Retail"));
// console.log(retialCompanies);

// // filter out all the companies that started in 80's
// const companies80 = companies.filter(company => (company.start >= 1980 && company.start < 1990));
// console.log(companies80);

// // all the companies that lasted 10 yrs
// const companyDuration = companies.filter(company => ((company.end - company.start) >= 10));
// console.log(companyDuration);

// ========================= map ==================== //
// const companyName = companies.map(function(company) {
//     return company.name;
// });
// console.log(companyName);

// const companyDesc = companies.map(company => {
//     return (`${company.name} :  ${company.start} - ${company.end}`);
// });
// console.log(companyDesc);



//  ======================= sort =================== //
// const sortedCompanies = companies.sort(function(c1, c2) {
//     if (c1.start > c2.start) return 1;
//     else return -1;
// });
// console.log(sortedCompanies);

// // sort ages : ascending order
// const sortAgesAscending = ages.sort((a, b) => (a - b));
// console.log(sortAgesAscending);

// // sort ages : descending order
// const sortAgesDescending = ages.sort((a, b) => (b - a));
// console.log(sortAgesDescending);

// ===================== reduce ==================== //

// sum the ages
// let ageSum = 0;
// for (let i = 0; i < ages.length; i++)
//     ageSum += ages[i];
// console.log(ageSum);

// const ageSum = ages.reduce(function(total, age) {
//     return (total + age);
// }, 0);
// console.log(ageSum);

// get total years of companies
// const totalCompanyYrs = companies.reduce((total, company) => {
//     return (total + (company.end - company.start));
// }, 0);
// console.log(totalCompanyYrs);

// // ES-6 way
// const totalCmpYr = companies.reduce((total, company) => total + (company.end - company.start), 0);
// console.log(totalCmpYr);

const combined = ages
    .map(age => (age * 2))
    .filter(age => (age >= 40))
    .sort((a, b) => (a - b))
    .reduce((a, b) => (a + b), 0);
console.log(combined);