$( document ).ready(function() {
   $("#hideBut").hide();
});

function ascii_to_hex(str)
{
	var arr1 = [];
	for (var n = 0, l = str.length; n < l; n ++) {
		var hex = Number(str.charCodeAt(n)).toString(16);
		arr1.push(hex);
	}
	return arr1.join('');
}

function showForm()
{
	$("#formRow").show();
	$("#hideBut").hide();
	$("#resMSG").remove();
}

function showMSG(msg, good)
{
	$("#formRow").hide();
	if (good) {
		$("#hideBut").prepend('<pre id="resMSG" class="text-center mt-5" style=color:green;font-size:20px>' + msg + '</pre>');
	} else {
		$("#hideBut").prepend('<pre id="resMSG" class="text-center mt-5" style=color:red;font-size:20px>' + msg + '</pre>');
	}
	$("#hideBut").show();
}

function sendForm()
{

	var formData = new FormData();
	formData.append("file", ascii_to_hex(document.getElementById("inputFile").value));
	formData.append("key", document.getElementById("inputKey").value);

	var req = new XMLHttpRequest();
	req.open('POST', 'index.php', true);
	req.onreadystatechange = function (aEvt) {
		if (req.readyState == 4 && req.status == 200) {
			$("#formCol").show();
			rtext = req.responseText
			if (rtext.includes("Invalid")) {
				showMSG(rtext, false);
			} else {
				showMSG(rtext, true)
			}

		}
	};
	req.send(formData);

}
