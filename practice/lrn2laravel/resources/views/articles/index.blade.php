@extends('app')

@section('content')

  <h1>Articles</h1>

  @foreach ($articles as $article)
    <article>
      <!-- many wayS
      <a href="/articles/{{ $article->id }}">  one way
      <a href="{{ url('/articles', $article->id) }}">  another
      <a href="{{ action('ArticlesController@show', [$article->id]) }}"> another -->
      <a href="{{ action('ArticlesController@show', [$article->id]) }}"><h2> {{ $article->title }}</h2></a>

      <div class="body">{{ $article->body }}</div>
    </article>
  @endforeach
@stop
