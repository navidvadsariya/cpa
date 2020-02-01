/**
 * WEB222 – Assignment 02
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 *
 *      Name: Navid Vadsariya
 *      Student ID: 136884186
 *      Date: 20 OCT 2019
 *
 */


var utils = {
   
    formatPhoneNumber: function(phoneNumber) {
        var phoneNoCopy = ('' + phoneNumber).replace(/\D/g, '')
        var match = phoneNoCopy.match(/^(\d{3})(\d{3})(\d{4})$/)
        if (match) {
          return '(' + match[1] + ') ' + match[2] + '-' + match[3]
        }     
    },

    generateUsername: function(firstName, lastName) {
        return (firstName.substr(0,2).toUpperCase() + lastName.substr(0,4).toUpperCase());
    } 
};


var users = {
   
    getUserCount: function(userList) {
        var result;
        if(userList === undefined || userList.length==0){
            result = 0;
            }
         else{
           result = userList.length;
            }
         return result;           
    },

   
    getStudents: function(userList) {
       
        const result =[];
        for(var i = 0; i< this.getUserCount(); i++){
        result[i] = userList[i].filter(userList => userList[i].isStudent === true);
        }
        return result;
    },

   
    getUsersWithGoodCredit: function(userList, minScore) {
        const result = [];
        for(var i = 0; i< this.getUserCount(); i++){
       result[i] = userList[i].filter(userList => userList.creditScore >= minScore);
        }
        return result;
    },

    
    setUsernames: function(userList) {
        userList.forEach(function(a){
           utils.getStudents(userList.firstName,userList.lastName);
        });
        return userList;
    },

    getPhoneList: function(userList) {
        // pass a function to map
        var result = [];
        for(var i = 0; i< this.getUserCount(); i++){
         result[i] = userList[i].map(userList => utils.formatPhoneNumber(userList[i].phone));
        }
       return ("name: " + userList.firstName + userList.lastName + result);

    },

    sortByDateOfBirth: function(userList) {
       return userList.birthDate.sort();
    }
};


