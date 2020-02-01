// Data for the "HTML Lists" Page

var fruits = ['Apples', 'Oranges', 'Pears', 'Grapes', 'Pineapples', 'Mangos'];

var directory = [
    { type: 'file', name: 'file1.txt' },
    { type: 'file', name: 'file2.txt' },
    {
        type: 'directory',
        name: 'HTML Files',
        files: [
            { type: 'file', name: 'file1.html' },
            { type: 'file', name: 'file2.html' }
        ]
    },
    { type: 'file', name: 'file3.txt' },
    {
        type: 'directory',
        name: 'JavaScript Files',
        files: [
            { type: 'file', name: 'file1.js' },
            { type: 'file', name: 'file2.js' },
            { type: 'file', name: 'file3.js' }
        ]
    }
];

 
window.onload = () => {
        var ol = document.createElement('ol');
		document.getElementById('fruits').appendChild(ol);
 
		fruits.forEach(function(fruit){
			var li = document.createElement('li');
			ol.appendChild(li);
			li.innerHTML += fruit;
        });


        var ul = document.createElement('ul');
        document.getElementById('directory').appendChild(ul);

        for (let i of directory) {
            if (i.type === 'directory') {
                var content = document.createElement('li');
                content.innerText += i.name;

                var subFiles = document.createElement('ul');
    
                for (let j of i.files) {
                    var subList = document.createElement('li');
                    subList.innerText = j.name;
                    subFiles.appendChild(subList);
                }
                ul.appendChild(content);
                ul.appendChild(subFiles);
            } 
            else {
                var content = document.createElement('li');
                ul.appendChild(content);
                content.innerText += i.name;
             }
        }
    };
    