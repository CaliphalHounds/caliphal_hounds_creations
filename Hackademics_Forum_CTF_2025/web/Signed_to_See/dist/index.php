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
