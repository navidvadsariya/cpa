function validateForm() {

    //call a function to validate name
    var isvalid = true;
    isvalid = validateName(isvalid, "first_name", "fnameError");
    isvalid = validateName(isvalid, "last_name", "lnameError");
    isvalid = validateAge(isvalid, "ageError");
    if(isvalid){
        alert("Form submitted successfully!");
    }
    return isvalid;
}
//this function should get first name form then validate then add display message in fname error
function validateName(isvalid, className,errorDiv) {
    var name = document.forms["signup"][className].value;
    var fieldName = className.replace("_", " ");

    var err = "";
    
    if (name.charAt(0) < "A" || name.charAt(0) > "Z") {
        err = "* first character of " + fieldName + " must be uppercase *";
    }
     // check all character are letters
    else if(name.match(/([^A-z])/g)){
        err = "* please enter alphabets only *";
        }
    document.getElementById(errorDiv).innerHTML = err;
    if (err.length > 0 || !isvalid) {
        return false;
    }
    else {
        return true;
    }
}
//validates age between 18-60
function validateAge(isvalid, errorDiv) {
    var age = document.forms["signup"]["age"].value;
    var err = "";
    if(age < 18 || age > 60){
        err = "* please enter a valid age(18-60) *"
    }
    document.getElementById(errorDiv).innerHTML = err;
    if (err.length > 0 || !isvalid) {
        return false;
    }
    else {
        return true;
    }
}




