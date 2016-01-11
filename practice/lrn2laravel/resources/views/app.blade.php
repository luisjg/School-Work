<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Document</title>
	<link type="text/css" rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css">
</head>

<body>
	<div class="container">
		@include('flash::message')
		<!-- @include('partials.flash') -->
		@yield('content')
	</div>
	<script type="text/javascript" src="//code.jquery.com/jquery.js"></script>
	<script type="text/javascript" src="//maxcdn.bootstrapcdn.com/bootstrap/3.3.6/bootstrap.min.js"></script>
	<script type="text/javascript">
	$('div.alert').not('.alert-important').delay(3000).slideUp(300);
	</script>
	@yield('footer')
</body>
</html>
