@extends('app')
@section('content')

    {!! Form::open(['url' => 'addClass']) !!}

    <div class="row">
        <div class="col-md-8 col-md-offset-2 form-horizontal">

            <h3>Add Class to Your List</h3>

            <div class="form-group invisible">
                <div class="col-sm-2">
                    {!! Form::label('user_id', 'User*') !!}
                </div>
                <div class="col-sm-4">
                    {!! Form::select('user_id',$users , null, ['class'=>'form-control']) !!}
                </div>
            </div>

            <div class="form-group">
                <div class="col-sm-2">
                    {!! Form::label('class_id', 'Class*') !!}
                </div>
                <div class="col-sm-4">
                    {!! Form::select('class_id',$classes , null, ['class'=>'form-control']) !!}
                </div>
            </div>

            <div class="form-group {{ ($errors->has('date_taken')) ? 'has-error' : '' }}">
                <div class="col-sm-2">
                    {!! Form::label('date_taken', 'Date Taken') !!}
                </div>
                <div class="col-sm-3">
                    {!! Form::text('date_taken', null, [ 'class'=>'form-control']) !!}
                    {{ ($errors->has('date_taken') ? $errors->first('date_taken') : '') }}
                </div>
            </div>

            <div class="form-group">
                <div class="col-sm-2">
                    {!! Form::label('note', 'Note') !!}
                </div>
                <div class="col-sm-8">
                    {!! Form::textarea('note', null, ['class'=>'form-control']) !!}
                </div>
            </div>

            <div class="form-group">
                <div class="col-sm-4 col-sm-offset-4">
                    {!! Form::submit('Add Class', ['class'=>'btn btn-primary form-control' ]) !!}
                </div>
            </div>
        </div>
    </div>
    {!! Form::close() !!}
@stop