<!DOCTYPE html>
<html lang="en">
<head>
	<link rel="stylesheet" href="https://cdn.rawgit.com/twbs/bootstrap/v4-dev/dist/css/bootstrap.css">
	<link href='http://fonts.googleapis.com/css?family=Lato&subset=latin,latin-ext' rel='stylesheet' type='text/css'>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/tether/1.1.1/js/tether.min.js"></script>
	<script src="https://cdn.rawgit.com/twbs/bootstrap/v4-dev/dist/js/bootstrap.js"></script>
	<style type="text/css">
		body {
			font-family: "Lato", sans-serif, monospace;
		}
	</style>
</head>
<body>
	<nav class="navbar navbar-light bg-faded">
	  <button class="navbar-toggler hidden-sm-up" type="button" data-toggle="collapse" data-target="#exCollapsingNavbar2">
	    &#9776;
	  </button>
	  <div class="collapse navbar-toggleable-xs" id="exCollapsingNavbar2">
	    <a class="navbar-brand" href="{{ url('/') }}">klinster</a>
	    <ul class="nav navbar-nav">
	      <li class="nav-item">
	        <a class="nav-link" href="{{ url('/') }}">About</a>
	      </li>
				<li class="nav-item">
	        <a class="nav-link" href="{{ url('/projects') }}">Projects</a>
	      </li>
	    </ul>
	  </div>
	</nav>
	<hr>
	<div class="container">
		@yield('content')
		<hr>
		<footer class="footer">
			<p>&copy; Company 2016</p>
		</footer>
	</div>
		@yield('footer')
</body>
</html>
