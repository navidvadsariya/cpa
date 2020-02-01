// All you JavaScript code for assignment 4 should be in this file

window.onload = function() { 
   generateTable();
   document.getElementById("menu_21").onclick = byPopulation;
   document.getElementById("menu_22").onclick = byPopulation_1;
   document.getElementById("menu_31").onclick = byKM_Americas;
   document.getElementById("menu_32").onclick = byKM_Asia;
   document.getElementById("menu_41").onclick = generateTable;
   document.getElementById("menu_42").onclick = generateTable_Arabic;
   document.getElementById("menu_43").onclick = generateTable_Chinese;
   document.getElementById("menu_44").onclick = generateTable_French;
   document.getElementById("menu_45").onclick = generateTable_hindi;
   document.getElementById("menu_46").onclick = generateTable_Korean;
   document.getElementById("menu_47").onclick = generateTable_Japanese;
   document.getElementById("menu_48").onclick = generateTable_Russian;
 };
 //**   
//Entire country list
//** 
function generateTable(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"English");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
}
//**   
//byPopulation (more than 100M)
//** 
 
 function byPopulation(){
  
      document.getElementById("subtitle").textContent="List of Countries and Dependencies - Population greater than 100 million";
      
      clearTable();
      var table = document.querySelector("#outputTable");
      var tableBody = document.createElement("tbody");
      for (var i = 0; i < countries.length; i++) { 
         if(countries[i].Population > 100000000){
         var row = createTable(i,"English");
           tableBody.appendChild(row); 
         }
      } 
      table.appendChild(tableBody);
   }
//**   
//byPopulation_1 (between 1~2 million)
//** 
 
function byPopulation_1(){
   document.getElementById("subtitle").textContent="List of Countries and Dependencies - Population between 1 and 2 million";
   clearTable();
      var table = document.querySelector("#outputTable");
      var tableBody = document.createElement("tbody");
      for (var i = 0; i < countries.length; i++) { 
         if(countries[i].Population >= 1000000 && countries[i].Population >= 2000000){
         var row = createTable(i,"English");
           tableBody.appendChild(row); 
         }
      } 
      table.appendChild(tableBody);

   tbl.appendChild(tblBody);
}
//**   
//byKM_Americas (area greater than 1 million)
//** 
function byKM_Americas(){
   document.getElementById("subtitle").textContent="List of Countries and Dependencies - Area greater than 1 million Km2, Americas";
   //country list   
   clearTable();
      var table = document.querySelector("#outputTable");
      var tableBody = document.createElement("tbody");
      for (var i = 0; i < countries.length; i++) { 
         if(countries[i].AreaInKm2 > 1000000 && countries[i].Continent === "Americas"){
         var row = createTable(i,"English");
           tableBody.appendChild(row); 
         }
      } 
      table.appendChild(tableBody);
      
   tbl.appendChild(tblBody);
}
//**   
//byKM_Asia (all countries)
//**  
function byKM_Asia(){
   document.getElementById("subtitle").textContent="List of Countries and Dependencies - All countries in Asia”";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      if(countries[i].Continent === "Asia"){
      var row = createTable(i,"English");
        tableBody.appendChild(row); 
      }
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}

//**   
//Entire country list (In different languages)
//** 
function generateTable_hindi(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies – Country/Dep. Name in Hindi";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"Hindi");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}
function generateTable_Arabic(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies – Country/Dep. Name in Hindi";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"Arabic");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}
function generateTable_Chinese(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies – Country/Dep. Name in Hindi";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"Chinese");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}
function generateTable_French(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies – Country/Dep. Name in Hindi";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"Franch");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}
function generateTable_Korean(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies – Country/Dep. Name in Hindi";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"Korean");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}
function generateTable_Japanese(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies – Country/Dep. Name in Hindi";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"Japanese");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}
function generateTable_Russian(){
   //h4
   document.getElementById("subtitle").textContent="List of Countries and Dependencies – Country/Dep. Name in Hindi";
   clearTable();
   var table = document.querySelector("#outputTable");
   var tableBody = document.createElement("tbody");
   for (var i = 0; i < countries.length; i++) { 
      var row = createTable(i,"Russian");
        tableBody.appendChild(row); 
   } 
   table.appendChild(tableBody);
   
tbl.appendChild(tblBody);
}

function clearTable(){
   var tbl = document.getElementById("outputTable");
   var tblExistingBody = tbl.querySelector("tbody");
   if (tblExistingBody){
    tbl.removeChild(tblExistingBody); 
   }
}
function createTable(i,language){
   
      var row = document.createElement("tr");
      row.appendChild(imgin(countries[i].Code));
      row.appendChild(getTdElement(countries[i].Code));
      row.appendChild(getTdElement(countries[i].Name[language]));
      row.appendChild(getTdElement(countries[i].Continent));
      row.appendChild(getTdElement(countries[i].AreaInKm2));
      row.appendChild(getTdElement(countries[i].Population));
      row.appendChild(getTdElement(countries[i].Capital));

    return row;
    
}

function getTdElement(text) {
   var cell = document.createElement("td");
   var cellText = document.createTextNode(text);
   cell.appendChild(cellText);
   return cell;
}

function imgin(code) {
   var newCode = code.toLowerCase();
   var x = document.createElement("img");
  
   x.setAttribute("src", "flags/"+ newCode + ".png");
   x.setAttribute("width", 35);
   x.setAttribute("heigth", 20);
   x.setAttribute("alt","");
  
   var cell = document.createElement("td");
   cell.appendChild(x);
   return x;
 }
 

