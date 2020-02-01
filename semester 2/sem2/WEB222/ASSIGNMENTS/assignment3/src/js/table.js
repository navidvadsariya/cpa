// Data for the "HTML Tables" Page

var users = [
    {
        first_name: 'Kaitlin',
        last_name: 'Burns',
        age: 23,
        email: 'kburns99753@usermail.com'
    },
    {
        first_name: 'Joshua',
        last_name: 'Feir',
        age: 31,
        email: 'josh319726@usermail.com'
    },
    {
        first_name: 'Stephen',
        last_name: 'Shaw',
        age: 28,
        email: 'steve.shaw47628@usermail.com'
    },
    {
        first_name: 'Timothy',
        last_name: 'McAlpine',
        age: 37,
        email: 'Timbo72469@usermail.com'
    },
    {
        first_name: 'Sarah',
        last_name: 'Connor',
        age: 19,
        email: 'SarahC6320@usermail.com'
    }
];


window.onload = () => {
    var t = document.createElement('table');
    document.getElementById('users').appendChild(t);

    var Head = document.createElement('thead');
    var row1 = document.createElement('tr');
    var head1 = document.createElement('th');
    var head2 = document.createElement('th');
    var head3 = document.createElement('th');
    var head4 = document.createElement('th');

    head1.innerText = 'First Name';
    head2.innerText = 'Last Name';
    head3.innerText = 'Age';
    head4.innerText = 'Email';
    row1.appendChild(head1);
    row1.appendChild(head2);
    row1.appendChild(head3);
    row1.appendChild(head4);
    Head.appendChild(row1);

    var tbody = document.createElement('tbody');

    for (let i of users) {

        var row = document.createElement('tr');
        var firstName = document.createElement('td');
        var lastName = document.createElement('td');
        var age = document.createElement('td');
        var email = document.createElement('td');
        var mail = document.createElement('a');


        firstName.innerText = i.first_name;
        lastName.innerText = i.last_name;
        age.innerText = i.age;
        mail.href = 'mailto:' + i.email;
        mail.innerText = i.email;

        email.appendChild(mail);
        row.appendChild(firstName);
        row.appendChild(lastName);
        row.appendChild(age);
        row.appendChild(email);
        tbody.appendChild(row);
        
        t.appendChild(Head);
        t.appendChild(tbody);
    }
   
};
