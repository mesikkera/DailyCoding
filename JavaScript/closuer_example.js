function outter() {
	var title = 'coding everybody';
	return function() {
		alert(title);
	}
}

inner = outter();

inner();
