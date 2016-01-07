@if(Session::has('flash_message'))
	<div class="alert alert-success {{ Session::has('fash_message_important') ? 'alert-important' : '' }}">
		@if(Session::has('flash_message_important'))
			<button type="button" class="close" data-dimiss="alert" aria-hidden="true">&times;</button>
		@endif
		{{ session('flash_message') }}
		<!-- Another way -->
		<!-- {{ Session::get('flash_message') }} -->
		</div>
@endif