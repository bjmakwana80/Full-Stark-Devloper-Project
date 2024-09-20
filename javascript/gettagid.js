let getId = (TagId) => document.getElementById(TagId);
//create alias for getId function
let $ = getId;

let setHtml = function(TagId,text=null)
{
    if(text!==null)
        $(TagId).innerHTML = text;
    else 
        return $(TagId).innerHTML;
}
//create alias for setHtml function
let $$ = setHtml;