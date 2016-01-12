<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Document</title>
	<link type="text/css" rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css">
	<link type="text/css" rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/select2/4.0.1/css/select2.min.css" />
</head>

<body>
	<div class="container">
		@include('flash::message')
		<!-- @include('partials.flash') -->
		@yield('content')
	</div>
	<!-- Scripts --> 
	<script type="application/javascript" src="https://code.jquery.com/jquery.js"></script>
	<script type="application/javascript" src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
	<script type="application/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/select2/4.0.1/js/select2.min.js"></script>
	<script type="application/javascript">
		$('div.alert').not('.alert-important').delay(3000).slideUp(300);
	</script>

	@yield('footer')
</body>
</html>
