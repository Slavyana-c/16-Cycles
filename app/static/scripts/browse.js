$(document).ready(function()
{
  function openNav() {
    document.getElementById("mySidebar").style.width = "250px";
    document.getElementById("main").style.marginLeft = "250px";
  }

  function closeNav() {
    document.getElementById("mySidebar").style.width = "0px";
    document.getElementById("main").style.marginLeft= "0";
  }

  function changeColour() {
    document.getElementById("button").style.backgroundColor = "red";
  }

  function refreshBrowse() {
    document.getElementById("startDate")
    document.getElementById("endDate")
    console.log("Test")
  }


  $('#delete').click(function() {
    alert(1);
    console.log("clicked");
    $.ajax({
        url: "/browse",
        type: "POST",
        contentType: "application/json;charset=UTF-8",
        dataType: "json",
        data: JSON.stringify({html_data: "hi"}),
        success: function(response) {
            console.log(response);
        },
    });
  });
});
