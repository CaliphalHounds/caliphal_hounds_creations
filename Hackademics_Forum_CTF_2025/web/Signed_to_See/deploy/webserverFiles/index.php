<?php

$secret = getenv('SECRET_KEY');
$files = array('test.txt', 'flag.txt');


if (isset($_POST['file']) && isset($_POST['key'])) {

	$reqFile = hex2bin($_POST['file']);
	$sig = sha1($secret . $reqFile);

	if (preg_match('/\w+\.txt$/', $reqFile, $matches) && in_array($matches[0], $files) && $_POST['key']===$sig) {
		$content = file_get_contents('/files/' . $matches[0]);
		die($content);
	} else {
		die('Invalid file or signature!');
	}

}

?>

<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<link rel="stylesheet" href="style.css" />
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>
<body class="bg-secondary">
<div class="con1 container h-100">
<h1 class="font-weight-bold text-center mb-5" id="txtTitle">Secure File Viewer</h1>


<div class="row mr-3 ml-3">
<div class="col text-center">

<h5>Welcome to our Secure File Viewer! Get the content of any available file by introducing the filename and secret signature of the file.</h5>
<span>Currently available files: ["test.txt", "flag.txt"]</span><br>
<span>Secret Signature of test.txt = c9d4b01ce16b640782af2864a47547d88fc02cab </span>
</div>
</div>
<div class="row mt-5 pt-5" id="formRow">
<div class="col mr-5 ml-5 pl-5 pr-5">
<form>
  <div class="form-group">
    <label for="inputFile" class="font-weight-bold">Filename:</label>
    <input type="text" class="form-control" id="inputFile" aria-describedby="fileHelp" placeholder="Enter filename">
  </div>
  <div class="form-group">
    <label for="inputKey" class="font-weight-bold">Secret Signature:</label>
    <input type="text" class="form-control" id="inputKey" placeholder="Enter the file secret signature">
  </div>
</form>
<button onclick="sendForm()" class="btn btn-primary float-right" id="myBut">Send</button>
</div>
</div>
<div class="row mt-5 pt-5">
<div class="col mr-5 ml-5 pl-5 pr-5 text-center">
<button onclick="showForm()" class="btn btn-info" id="hideBut">Back</button>
</div>
</div>


<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
<script src="functions.js"></script>
</div>
</body>
</html>
